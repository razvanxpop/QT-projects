#pragma once
#include <string>
#include <vector>

using namespace std;

class Volunteer {
private:
	string name;
	string email;
	vector<string> interests;
	string department;

public:
	Volunteer() : department("No department") {}
	Volunteer(const string& name, const string& email, const vector<string> interests, const string& department) : name(name), email(email), interests(interests), department(department) {}

	string getName() const { return name; }
	string getEmail() const { return email; }
	vector<string> getInterests() const { return interests; }
	string getDepartment() const { return department; }

	friend istream& operator>>(istream& is, Volunteer& volunteer);
	friend ostream& operator<<(ostream& os, const Volunteer& volunteer);

	string toString() const;

	bool operator==(const Volunteer& other) {
		return this->name == other.name && this->email == other.email;
	}

	bool operator!=(const Volunteer& other) {
		return !(*this == other);
	}

	void operator=(const Volunteer& other) {
		this->name = other.name;
		this->email = other.email;
		this->interests = other.interests;
		this->department = other.department;
	}
};