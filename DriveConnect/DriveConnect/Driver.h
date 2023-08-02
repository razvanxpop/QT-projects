#pragma once
#include <string>

using namespace std;

class Driver {
private:
	string name;
	pair<int, int> location;
	int score;
public:
	Driver() = default;
	Driver(const string& name, pair<int, int> location, int score) : name(name), location(location), score(score) {}

	string getName() const { return name; }
	pair<int, int> getLocation() const { return location; }
	int getScore() const { return score; }

	friend istream& operator>>(istream& is, Driver& driver);
};