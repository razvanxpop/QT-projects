#include "Report.h"
#include "utils.h"

istream& operator>>(istream& is, Report& report) {
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(trim(line), ';');
	if (tokens.size() != 4)
		return is;
	report.description = trim(tokens[0]);
	report.reporter = trim(tokens[1]);
	vector<string> locationTokens = tokenize(trim(tokens[2]), ',');
	if (locationTokens.size() != 2)
		return is;
	report.location = make_pair(stoi(trim(locationTokens[0])), stoi(trim(locationTokens[1])));
	report.status = stoi(trim(tokens[3]));

	return is;
}

ostream& operator<<(ostream& os, const Report& report) {
	os << report.description << ";" << report.reporter << ";" << report.location.first << "," << report.location.second << ";" << report.status;
	return os;
}

string Report::toString() const {
	return description + ";" + reporter + ";" + to_string(location.first) + "," + to_string(location.second) + ";" + to_string(status);
}
