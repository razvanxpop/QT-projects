#include "utils.h"

string trim(const string& str) {
	string result = str;
	while (!result.empty() && result[0] == ' ')
		result.erase(0, 1);
	while (!result.empty() && result[result.size() - 1] == ' ')
		result.erase(result.size() - 1, 1);
	return result;
}

vector<string> tokenize(const string& str, char delim) {
	stringstream ss(str);
	string token;
	vector<string> tokens;
	while (getline(ss, token, delim))
		tokens.push_back(token);
	return tokens;
}
