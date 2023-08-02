#include "Package.h"
#include "utils.h"

istream& operator>>(istream& is, Package& package) {
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 4)
		return is;

	package.recipient = trim(tokens[0]);
	vector<string> adressTokens = tokenize(trim(tokens[1]), ',');
	if (adressTokens.size() != 2)
		return is;
	package.adress = make_pair(trim(adressTokens[0]), stoi(trim(adressTokens[1])));
	vector<string> locationTokens = tokenize(trim(tokens[2]), ',');
	if (locationTokens.size() != 2)
		return is;
	package.location = make_pair(stoi(trim(locationTokens[0])), stoi(trim(locationTokens[1])));
	package.status = stoi(trim(tokens[3]));

	return is;
}

ostream& operator<<(ostream& os, const Package& package) {
	os << package.recipient << ";" << package.adress.first << "," << package.adress.second
		<< ";" << package.location.first << "," << package.location.second << ";" << package.status;
	return os;
}

string Package::toString() const {
	return this->recipient + ';' + this->adress.first + "," + to_string(this->adress.second) + ";" + to_string(this->location.first) + "," + to_string(this->location.second) + ";" + to_string(this->status) + '\n';

}
