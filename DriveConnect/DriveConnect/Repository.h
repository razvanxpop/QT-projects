#pragma once
#include "Driver.h"
#include "Report.h"

#include <vector>

class Repository {
private:
	vector<Driver> drivers;
	vector<Report> reports;
	string driversFile;
	string reportsFile;
public:
	Repository(const string& driversFile, const string& reportsFile);

	vector<Report>& getReports() { return reports; }
	vector<Driver>& getDrivers() { return drivers; }
	Driver* getDriver(int index) { return &drivers[index]; }

	void addReport(const Report& report);
	void validateReport(Report& report);

private:
	void loadDrivers();
	void loadReports();
	void saveReports();
};