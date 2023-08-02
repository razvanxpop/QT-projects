#include "Repository.h"

#include <fstream>

Repository::Repository(const string& departmentsFile, const string& volunteersFile) {
	this->departmentsFile = departmentsFile;
	this->volunteersFile = volunteersFile;
	loadDepartments();
	loadVolunteers();
}

void Repository::addVolunteer(const Volunteer& volunteer) {
	auto it = find(volunteers.begin(), volunteers.end(), volunteer);
	if (it == volunteers.end()) {
		volunteers.push_back(volunteer);
		saveVolunteers();
		return;
	}
	throw runtime_error("The volunteer already exists!");
}

void Repository::assignVolunteer(const Volunteer& volunteer) {
	auto it = find(volunteers.begin(), volunteers.end(), volunteer);
	if (it != volunteers.end()) {
		*it = volunteer;
		saveVolunteers();
		return;
	}
	throw runtime_error("The volunteer selecteed was not found!");
}

void Repository::loadDepartments() {
	ifstream fin(departmentsFile);
	if (!fin.is_open())
		throw runtime_error("Could not open the departments file for reading!");
	Department department;
	while (fin >> department)
		departments.push_back(department);

	fin.close();
}

void Repository::loadVolunteers() {
	ifstream fin(volunteersFile);
	if (!fin.is_open())
		throw runtime_error("Could not open the volunteers file for reading!");
	while (!fin.eof()) {
		Volunteer volunteer;
		fin >> volunteer;
		volunteers.push_back(volunteer);
	}

	fin.close();
}

void Repository::saveVolunteers() {
	ofstream fout(volunteersFile);
	if (!fout.is_open())
		throw runtime_error("Could not open the volunteers file for writing!");
	for (auto volunteer : volunteers)
		fout << volunteer << '\n';

	fout.close();
}
