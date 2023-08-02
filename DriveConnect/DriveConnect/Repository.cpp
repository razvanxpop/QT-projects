#include "Repository.h"

#include <fstream>

Repository::Repository(const string& driversFile, const string& reportsFile) {
	this->driversFile = driversFile;
	this->reportsFile = reportsFile;
	loadDrivers();
	loadReports();
}

void Repository::addReport(const Report& report) {
	auto it = find(reports.begin(), reports.end(), report);
	if (it == reports.end()) {
		reports.push_back(report);
		saveReports();
		return;
	}
	throw runtime_error("The report already exists!");
}

void Repository::validateReport(Report& report) {
	auto it = find(reports.begin(), reports.end(), report);

	it->setStatus(true);
	saveReports();
}

void Repository::loadDrivers() {
	ifstream fin(driversFile);
	if (!fin.is_open())
		throw runtime_error("Could not open the direvers file for reading!");
	Driver driver;
	while (fin >> driver)
		drivers.push_back(driver);
	fin.close();
}

void Repository::loadReports() {
	ifstream fin(reportsFile);
	if (!fin.is_open())
		throw runtime_error("Could not open the reports file for reading!");
	Report report;
	while (fin >> report)
		reports.push_back(report);
	fin.close();
}

void Repository::saveReports() {
	ofstream fout(reportsFile);
	if (!fout.is_open())
		throw runtime_error("Could not open the reports file for writing!");
	for (auto report : reports)
		fout << report << '\n';
	fout.close();
}
