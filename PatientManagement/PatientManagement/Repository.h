#pragma once
#include "Doctor.h"
#include "Patient.h"

#include <vector>

using namespace std;

class Repository {
private:
	vector<Doctor> doctors;
	vector<Patient> patients;
	string doctorsFile;
	string patientsFile;

public:
	Repository(const string& doctorsFile, const string& patientsFile);

	vector<Doctor>& getDoctors() { return doctors; }
	vector<Patient>& getPatients() { return patients; }
	Doctor* getDoctor(int index) { return &doctors[index]; }

	void addPatient(const Patient& patient);
	void updatePatient(const Patient& patient, const string& newDiagnosis, const string& newSpecialization, const string& newDoctor);
private:
	void loadDoctors();
	void loadPatients();
	void savePatients();
};