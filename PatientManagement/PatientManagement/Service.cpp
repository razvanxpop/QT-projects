#include "Service.h"
#include "utils.h"

#include <algorithm>
#include <iterator>

vector<Patient> Service::getPatientsBySpecialization(const string& specialization) {
	vector<Patient> filteredPatients;
	vector<Patient> patients = repository.getPatients();
	copy_if(patients.begin(), patients.end(), back_inserter(filteredPatients), [specialization](const Patient& patient) {
		return patient.getSpecialization() == specialization || (patient.getDiagnosis() == "undiagnosed" && patient.getSpecialization() == "");
	});

	return filteredPatients;
}

vector<Patient> Service::getPatientsByDoctor(const string& name) {
	vector<Patient> patients = repository.getPatients();
	vector<Patient> filteredPatients;
	copy_if(patients.begin(), patients.end(), back_inserter(filteredPatients), [name](const Patient& patient) {
		return patient.getDoctor() == name;
	});

	return filteredPatients;
}

void Service::addPatient(const string& name, const string& diagnosis, const string& specialization, const string& doctor, const string& date) {
	if (name == "")
		throw exception("Invalid name!");
	int day, month, year;
	try {
		vector<string> dateTokens = tokenize(trim(date), '-');
		day = stoi(trim(dateTokens[0]));
		month = stoi(trim(dateTokens[1]));
		year = stoi(trim(dateTokens[2]));
	}
	catch (const exception& e) {
		throw exception(e.what());
	}

	Patient patient{ name, diagnosis, specialization, doctor, Date(day, month, year) };
	repository.addPatient(patient);
	this->notify();
}

void Service::updatePatient(const string& name, const string& diagnosis, const string& specialization, const string& doctor, const string& date, const string& newDiagnosis, const string& newSpecialization, const string& newDoctor) {
	int day, month, year;
	vector<string> dateTokens = tokenize(trim(date), '-');
	try {
		day = stoi(trim(dateTokens[0]));
		month = stoi(trim(dateTokens[1]));
		year = stoi(trim(dateTokens[2]));
	}
	catch (const exception& e) {
		throw runtime_error(e.what());
	}
	Patient patient{ name, diagnosis, specialization, doctor, Date(day, month, year) };
	repository.updatePatient(patient, newDiagnosis, newSpecialization, newDoctor);
	this->notify();
}
