#include "Doctor.h"
#include "utils.h"

Doctor::Doctor(const string& name, const string& specialization) {
	this->name = name;
	this->specialization = specialization;
}

istream& operator>>(istream& is, Doctor& doctor) {
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(trim(line), ';');
	if (tokens.size() != 2)
		return is;

	doctor.name = trim(tokens[0]);
	doctor.specialization = trim(tokens[1]);

	return is;
}
