#include "Service.h"
#include "utils.h"

#include <algorithm>
#include <iterator>

vector<Volunteer> Service::getVolunteersByDepartment(const string& department) {
	vector<Volunteer> volunteers = repository.getVolunteers();
	vector<Volunteer> filteredVolunteers;
	copy_if(volunteers.begin(), volunteers.end(), back_inserter(filteredVolunteers), [department](const Volunteer& volunteer) {
		return department == volunteer.getDepartment();
	});

	return filteredVolunteers;
}

vector<Volunteer> Service::getUnassignedVolunteers() {
	vector<Volunteer> volunteers = repository.getVolunteers();
	vector<Volunteer> filteredVolunteers;
	copy_if(volunteers.begin(), volunteers.end(), back_inserter(filteredVolunteers), [](const Volunteer& volunteer) {
		return volunteer.getDepartment() == "No department";
	});

	return filteredVolunteers;
}

void Service::addVolunteer(const string& name, const string& email, const string& interests, const string& department) {
	vector<string> interestsTokens = tokenize(trim(interests), ',');
	vector<string> _interests;
	for (string token : interestsTokens)
		_interests.push_back(token);
	Volunteer volunteer(trim(name), trim(email), _interests, trim(department));
	repository.addVolunteer(volunteer);
	this->notify();
}

void Service::assignVolunteer(const string& volunteerString, const string& department) {
	vector<string> tokens = tokenize(trim(volunteerString), ';');
	string volunteerDepartment = trim(tokens[3]);
	if (volunteerDepartment != "No department")
		throw runtime_error("The selected volunteer has a department assigned!");
	string name = trim(tokens[0]);
	string email = trim(tokens[1]);
	vector<string> interests;
	vector<string> interestsTokens = tokenize(trim(tokens[2]), ',');
	for (string token : interestsTokens)
		interests.push_back(token);
	Volunteer volunteer(name, email, interests, department);
	repository.assignVolunteer(volunteer);
	this->notify();
}
