#include "Driver.h"
#include "utils.h"

istream& operator>>(istream& is, Driver& driver) {
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(trim(line), ';');
	if (tokens.size() != 3)
		return is;
	driver.name = trim(tokens[0]);
	vector<string> locationTokens = tokenize(trim(tokens[1]), ',');
	if (locationTokens.size() != 2)
		return is;
	driver.location = make_pair(stoi(trim(locationTokens[0])), stoi(trim(locationTokens[1])));
	driver.score = stoi(trim(tokens[2]));

	return is;
}
