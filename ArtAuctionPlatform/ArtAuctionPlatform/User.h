#pragma once
#include <string>

using namespace std;

class User {
private:
	string name;
	int id;
	string type;
public:
	User() = default;
	User(const string& name, const int id, const string& type) : name(name), id(id), type(type) {}

	string getName() const { return name; }
	int getId() const { return id; }
	string getType() const { return type; }

	friend istream& operator>>(istream& is, User& user);
};