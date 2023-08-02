#include "Patient.h"
#include "utils.h"

Patient::Patient(const string& name, const string& diagnosis, const string& specialization, const string& doctor, const Date& date) {
	this->name = name;
	this->diagnosis = diagnosis;
	this->specialization = specialization;
	this->doctor = doctor;
	this->date = date;
}

string Patient::toString() const {
	return this->name + ";" + this->diagnosis + ";" + this->specialization + ";" + this->doctor + ";"
		+ to_string(this->date.getDay()) + "-" + to_string(this->date.getMonth()) + "-" + to_string(this->date.getYear());
}

istream& operator>>(istream& is, Patient& patient) {
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(trim(line), ';');
	if (tokens.size() != 5)
		return is;
	patient.name = trim(tokens[0]);
	patient.diagnosis = trim(tokens[1]);
	patient.specialization = trim(tokens[2]);
	patient.doctor = trim(tokens[3]);
	vector<string> dateTokens = tokenize(trim(tokens[4]), '-');
	if (dateTokens.size() != 3)
		return is;
	Date date(stoi(trim(dateTokens[0])), stoi(trim(dateTokens[1])), stoi(trim(dateTokens[2])));
	patient.date = date;

	return is;
}

ostream& operator<<(ostream& os, const Patient& patient) {
	os << patient.name << ";" << patient.diagnosis << ";" << patient.specialization << ";" << patient.doctor << ";"
		<< patient.date.getDay() << "-" << patient.date.getMonth() << "-" << patient.date.getYear();
	return os;
}
