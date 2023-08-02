#include "Volunteer.h"
#include "utils.h"

istream& operator>>(istream& is, Volunteer& volunteer) {
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(trim(line), ';');
	if (tokens.size() != 4)
		return is;

	volunteer.name = trim(tokens[0]);
	volunteer.email = trim(tokens[1]);
	vector<string> interestsTokens = tokenize(trim(tokens[2]), ',');
	for (string token : interestsTokens)
		volunteer.interests.push_back(trim(token));
	volunteer.department = trim(tokens[3]);

	return is;
}

ostream& operator<<(ostream& os, const Volunteer& volunteer) {
	os << volunteer.name << ";" << volunteer.email << ";";
	for (int index = 0; index < volunteer.interests.size(); ++index) {
		os << volunteer.interests[index];
		if (index != volunteer.interests.size() - 1)
			os << ",";
	}
	os << ";" << volunteer.department;

	return os;
}

string Volunteer::toString() const{
	string output = name + ";" + email + ";";
	for (int index = 0; index < interests.size(); ++index) {
		output += interests[index];
		if (index < interests.size() - 1)
			output += ",";
	}
	output += ";" + department;

	return output;
}
