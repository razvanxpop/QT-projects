#pragma once
#include <string>
#include <vector>

using namespace std;

class Courier {
private:
	string name;
	vector<string> streets;
	pair<pair<int, int>, int> zone;
public:
	Courier() = default;
	Courier(const string& name, const vector<string> streets, const pair<pair<int, int>, int> zone) : name(name), streets(streets), zone(zone) {}

	string getName() const { return name; }
	vector<string> getStreets() const { return streets; }
	pair<pair<int, int>, int> getZone() const { return zone; }

	void setName(const string& newName) { name = newName; }
	void setStreets(const vector<string> newStreets) { streets = newStreets; }
	void setZone(const pair<pair<int, int>, int> newZone) { zone = newZone; }

	friend istream& operator>>(istream& is, Courier& courier);
};