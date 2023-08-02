#pragma once
#include <string>
using namespace std;
class Department {
private:
	string name;
	string description;
public:
	Department() = default;
	Department(const string& name, const string& description) : name(name), description(description) {}

	string getName() const { return name; }
	string getDescription() const { return description; }

	friend istream& operator>>(istream& is, Department& department);
};