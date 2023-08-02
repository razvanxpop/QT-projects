#include "Repository.h"

#include <fstream>

Repository::Repository(const string& doctorsFile, const string& patientsFile) {
	this->doctorsFile = doctorsFile;
	this->patientsFile = patientsFile;
	loadDoctors();
	loadPatients();
}

void Repository::addPatient(const Patient& patient) {
	auto it = find(patients.begin(), patients.end(), patient);
	if (it == patients.end())
		patients.push_back(patient);
	else
		throw runtime_error("The patient already exists!");
	savePatients();
}

void Repository::updatePatient(const Patient& patient, const string& newDiagnosis, const string& newSpecialization, const string& newDoctor) {
	auto it = find(patients.begin(), patients.end(), patient);
	if (it != patients.end()) {
		it->setDiagnosis(newDiagnosis);
		it->setSpecialization(newSpecialization);
		it->setDoctor(newDoctor);
		savePatients();	
		return;
	}
	throw runtime_error("The patient does not exist!");
}

void Repository::loadDoctors() {
	ifstream fin(doctorsFile);
	if (!fin.is_open())
		throw runtime_error("Could not open the doctors file for reading!");

	Doctor doctor;
	while (fin >> doctor)
		doctors.push_back(doctor);

	fin.close();
}

void Repository::loadPatients() {
	ifstream fin(patientsFile);
	if (!fin.is_open())
		throw runtime_error("Could not open patients file for reading!");

	Patient patient;
	while (fin >> patient)
		patients.push_back(patient);

	fin.close();
}

void Repository::savePatients() {
	ofstream fout(patientsFile);
	if (!fout.is_open())
		throw runtime_error("Could not open the patients file for writing!");
	for (auto patient : patients)
		fout << patient << '\n';

	fout.close();
}
