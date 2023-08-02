#pragma once
#include <string>
using namespace std;

class Package {
private:
	string recipient;
	pair<string, int> adress;
	pair<int, int> location;
	bool status;

public:
	Package() : status(false) {}
	Package(const string& recipient, const pair<string, int> adress, const pair<int, int> location, bool status) : recipient(recipient), adress(adress), location(location), status(status) {}

	string getRecipient() const { return recipient; }
	pair<string, int> getAdress() const { return adress; }
	pair<int, int> getLocation() const { return location; }
	bool getStauts() const { return status; }

	void setRecipient(const string& newRecipeint) { recipient = newRecipeint; }
	void setAdress(const pair<string, int> newAdress) { adress = newAdress; }
	void setLocation(const pair<int, int> newLocation) { location = newLocation; }
	void setStauts(bool newStatus) { status = newStatus; }

	friend istream& operator>>(istream& is, Package& package);
	friend ostream& operator<<(ostream& os, const Package& package);

	string toString() const;

	bool operator==(const Package& other) {
		return this->recipient == other.recipient && this->adress == other.adress && this->location == other.location && this->status == other.status;
	}

	bool operator!=(const Package& other) {
		return !(*this == other);
	}
};