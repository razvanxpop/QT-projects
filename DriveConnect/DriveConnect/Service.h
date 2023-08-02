#pragma once
#include "Subject.h"
#include "Repository.h"

class Service : public Subject {
private:
	Repository& repository;
	vector<string> messages;
public:
	Service(Repository& repository) : repository(repository) {}

	vector<Report>& getReports() { return repository.getReports(); }
	vector<string> getMessages() { return messages; }

	void addReport(const string& description, const string& location, const string& driver, const string& driverLocation);
	void addMessage(const string& message);
	void validateReport(const string& reportString, const string& driverName);
};