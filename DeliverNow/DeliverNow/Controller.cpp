#include "Controller.h"
#include "utils.h"

#include <fstream>
#include <algorithm>


#define PI 3.14159265359
#include <math.h>

Controller::Controller(const string& couriersFile, const string& packagesFile) {
	this->couriersFile = couriersFile;
	this->packagesFile = packagesFile;
	loadCouriers();
	loadPackages();
}

vector<Package> Controller::getUndeliverdPackages(Courier* courier) {
	vector<Package> filteredPackages;
	copy_if(this->packages.begin(), this->packages.end(), back_inserter(filteredPackages), [&, courier](const Package& package) {
		if (package.getStauts() == false) {
			vector<string> streets = courier->getStreets();
			auto it = find(streets.begin(), streets.end(), package.getAdress().first + " " + to_string(package.getAdress().second));
			if (it != streets.end())
				return true;
			else {
				double packageLatitude = package.getLocation().first * PI / 180.0;
				double packageLongitude = package.getLocation().second * PI / 180.0;
				double courierLatitude = courier->getZone().first.first * PI / 180.0;
				double courierLongitude = courier->getZone().first.second * PI / 180.0;

				double distanceLatitude = courierLatitude - packageLatitude;
				double distanceLongitude = courierLongitude - packageLongitude;

				double a = sin(distanceLatitude / 2) * sin(distanceLongitude / 2) + cos(packageLatitude) * cos(courierLatitude) * sin(distanceLongitude / 2) * sin(distanceLongitude / 2);
				double c = 2 * atan2(sqrt(a), sqrt(1 - a));
				double distance = c * courier->getZone().second;
				if (distance <= courier->getZone().second)
					return true;
			}
		}
		return false;
	});

	return filteredPackages;
}

vector<Package> Controller::getPackagesOnTheSelectedStreet(const string& street) {
	vector<Package> filteredPackages;
	copy_if(packages.begin(), packages.end(), back_inserter(filteredPackages), [street](const Package& package) {
		return street == package.getAdress().first + " " + to_string(package.getAdress().second);
	});

	return filteredPackages;
}

void Controller::deliverPackage(const string& recipient, pair<string, int> adress, pair<int, int> location, bool status) {
	Package package(recipient, adress, location, status);
	auto it = find(packages.begin(), packages.end(), package);
	if (it != packages.end()) {
		it->setStauts(true);
		this->savePackages();
		this->notify();
		return;
	}
	throw runtime_error("Did not find the selected package!");
}

void Controller::addPackage(const string& recipient, const string& adress, const string& location) {
	string street;
	int streetNumber, latitude, longitude;
	try {
		vector<string> adressTokens = tokenize(trim(adress), ',');
		street = trim(adressTokens[0]);
		streetNumber = stoi(trim(adressTokens[1]));
		vector<string> locationTokens = tokenize(trim(location), ',');
		latitude = stoi(trim(locationTokens[0]));
		longitude = stoi(trim(locationTokens[1]));
	}
	catch (const exception& e) {
		throw runtime_error(e.what());
	}
	pair<string, int> _adress = make_pair(street, streetNumber);;
	pair<int, int> _location = make_pair(latitude, longitude);;
	Package package(recipient, _adress, _location, false);
	auto it = find(packages.begin(), packages.end(), package);
	if (it == packages.end()) {
		this->packages.push_back(package);
		this->savePackages();
		this->notify();
		return;
	}
	throw runtime_error("The package already exists!");
}

void Controller::loadCouriers() {
	ifstream file(couriersFile);
	if (!file.is_open())
		throw runtime_error("Could not open the couriers file for reading!");
	while (!file.eof()) {
		Courier courier;
		file >> courier;
		couriers.push_back(courier);
	}

	file.close();
}

void Controller::loadPackages() {
	ifstream file(packagesFile);
	if (!file.is_open())
		throw runtime_error("Could not open the packages file for reading!");
	Package package;
	while (file >> package)
		packages.push_back(package);

	file.close();
}

void Controller::savePackages() {
	ofstream file(packagesFile);
	if (!file.is_open())
		throw runtime_error("Could not open the packages file for writing!");
	for (auto package : packages)
		file << package << '\n';

	file.close();
}
