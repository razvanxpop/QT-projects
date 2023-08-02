#pragma once

#include "Courier.h"
#include "Package.h"
#include "Subject.h"

#include <vector>

using namespace std;

class Controller : public Subject {
private:
	vector<Courier> couriers;
	vector<Package> packages;
	string couriersFile;
	string packagesFile;

public:
	Controller(const string& couriersFile, const string& packagesFile);

	vector<Courier>& getCouriers() { return couriers; }
	vector<Package>& getPackages() { return packages; }
	Courier* getCourier(int index) { return &couriers[index]; }

	vector<Package> getUndeliverdPackages(Courier* courier);
	vector<Package> getPackagesOnTheSelectedStreet(const string& street);
	void deliverPackage(const string& recipient, pair<string, int> adress, pair<int, int> location, bool status);
	void addPackage(const string& recipient, const string& adress, const string& location);

private:
	void loadCouriers();
	void loadPackages();
	void savePackages();
};