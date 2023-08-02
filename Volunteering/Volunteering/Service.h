#pragma once
#include "Repository.h"
#include "Subject.h"

class Service : public Subject {
private:
	Repository& repository;
public:
	Service(Repository& repository) : repository(repository) {}

	vector<Department>& getDepartments() { return repository.getDepartments(); }
	vector<Volunteer>& getVolunteers() { return repository.getVolunteers(); }
	vector<Volunteer> getVolunteersByDepartment(const string& department);
	vector<Volunteer> getUnassignedVolunteers();

	void addVolunteer(const string& name, const string& email, const string& interests, const string& department);
	void assignVolunteer(const string& volunteerString, const string& department);
};