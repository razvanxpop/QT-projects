#include "User.h"
#include "utils.h"

istream& operator>>(istream& is, User& user) {
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(trim(line), ';');
	if (tokens.size() != 3)
		return is;
	user.name = trim(tokens[0]);
	user.id = stoi(trim(tokens[1]));
	user.type = trim(tokens[2]);

	return is;
}
