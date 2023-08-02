#include "Courier.h"
#include "utils.h"

istream& operator>>(istream& is, Courier& courier) {
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 3)
		return is;

	courier.name = trim(tokens[0]);
	vector<string> streetTokens = tokenize(trim(tokens[1]), ',');
	for (string token : streetTokens)
		courier.streets.push_back(trim(token));
	vector<string> zoneTokens = tokenize(trim(tokens[2]), ',');
	if (zoneTokens.size() != 3)
		return is;
	courier.zone = make_pair(make_pair(stoi(trim(zoneTokens[0])), stoi(trim(zoneTokens[1]))), stoi(trim(zoneTokens[2])));
	
	return is;
}
