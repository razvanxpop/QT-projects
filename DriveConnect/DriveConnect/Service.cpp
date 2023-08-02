#include "Service.h"
#include "utils.h"

#include <cmath>

void Service::addReport(const string& description, const string& driver, const string& location, const string& driverLocation) {
	vector<string> locationTokens = tokenize(trim(location), ',');
	if (locationTokens.size() != 2)
		throw runtime_error("Invalid location!");
	int reportLatitude, reportLongitude;
	try {
		reportLatitude = stoi(trim(locationTokens[0]));
		reportLongitude = stoi(trim(locationTokens[1]));
	}
	catch (const exception& e) {
		throw runtime_error(e.what());
	}

	locationTokens = tokenize(trim(driverLocation), ',');
	int driverLatitude, driverLongitude;
	driverLatitude = stoi(trim(locationTokens[0]));
	driverLongitude = stoi(trim(locationTokens[1]));
	if (sqrt(pow(driverLatitude - reportLatitude, 2) + pow(driverLongitude - reportLongitude, 2)) > 20)
		throw runtime_error("The location of the report is too far from the driver current location!");
	Report report(description, driver, make_pair(reportLatitude, reportLongitude), false);
	repository.addReport(report);
	this->notify();
}

void Service::addMessage(const string& message) {
	messages.push_back(message);
	this->notify();
}

void Service::validateReport(const string& reportString, const string& driverName) {
	vector<string> tokens = tokenize(trim(reportString), ';');
	bool status = stoi(trim(tokens[3]));
	if (status != 0)
		throw runtime_error("The report is already validated!");
	string reporter = trim(tokens[1]);
	if (reporter == driverName)
		throw runtime_error("You can not validate your own report!");
	string description = trim(tokens[0]);
	vector<string> locationTokens = tokenize(trim(tokens[2]), ',');
	pair<int, int> location = make_pair(stoi(trim(locationTokens[0])), stoi(trim(locationTokens[1])));
	Report report(description, reporter, location, status);
	repository.validateReport(report);
	this->notify();
}
