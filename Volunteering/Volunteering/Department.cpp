#include "Department.h"
#include "utils.h"

istream& operator>>(istream& is, Department& department) {
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(trim(line), ';');
	if (tokens.size() != 2)
		return is;
	department.name = trim(tokens[0]);
	department.description = trim(tokens[1]);

	return is;
}
