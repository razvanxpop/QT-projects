#pragma once
#include <string>

using namespace std;

class Doctor {
private:
	string name;
	string specialization;
public:
	Doctor() = default;
	Doctor(const string& name, const string& specialization);

	string getName() const { return name; }
	string getSpecialization() const { return specialization; }

	friend istream& operator>>(istream& is, Doctor& doctor);
};