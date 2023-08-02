#pragma once
#include "Department.h"
#include "Volunteer.h"

#include <vector>

using namespace std;

class Repository {
private:
	vector<Department> departments;
	vector<Volunteer> volunteers;
	string departmentsFile;
	string volunteersFile;

public:
	Repository(const string& departmentsFile, const string& volunteersFile);

	vector<Volunteer>& getVolunteers() { return volunteers; }
	vector<Department>& getDepartments() { return departments; }
	Department* getDepartment(int index) { return &departments[index]; }

	void addVolunteer(const Volunteer& volunteer);
	void assignVolunteer(const Volunteer& volunteer);

private:
	void loadDepartments();
	void loadVolunteers();
	void saveVolunteers();
};