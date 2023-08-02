#pragma once
#include <string>

using namespace std;

class Report {
private:
	string description;
	string reporter;
	pair<int, int> location;
	bool status;
public:
	Report() = default;
	Report(const string& description, const string& reporter, pair<int, int> location, bool status) : description(description), reporter(reporter), location(location), status(status) {}

	string getDescription() const { return description; }
	string getReporter() const { return reporter; }
	pair<int, int> getLocation() const { return location; }
	bool getStatus() const { return status; }

	void setStatus(bool newStatus) { status = newStatus; }

	friend istream& operator>>(istream& is, Report& report);
	friend ostream& operator<<(ostream& os, const Report& report);

	string toString() const;

	bool operator==(const Report& other) {
		return this->description == other.description && this->reporter == other.reporter && this->location == other.location;
	}

	bool operator!=(const Report& other) {
		return !(*this == other);
	}
};