#pragma once
#include "Repository.h"
#include "Subject.h"

class Service : public Subject {
private:
	Repository& repository;

public:
	Service(Repository& repository) : repository(repository) {}

	vector<Doctor>& getDoctors() { return repository.getDoctors(); }
	vector<Patient>& getPatients() { return repository.getPatients(); }
	vector<Patient> getPatientsBySpecialization(const string& specialization);
	vector<Patient> getPatientsByDoctor(const string& name);
	Doctor* getDoctor(int index) { return repository.getDoctor(index); }

	void addPatient(const string& name, const string& diagnosis, const string& specialization, const string& doctor, const string& date);
	void updatePatient(const string& name, const string& diagnosis, const string& specialization, const string& doctor, const string& date, const string& newDiagnosis, const string& newSpecialization, const string& newDoctor);
};