#include "Item.h"
#include "utils.h"
#include <algorithm>

istream& operator>>(istream& is, Item& item) {
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(trim(line), ';');
	if (tokens.size() != 4)
		return is;
	item.name = trim(tokens[0]);
	item.category = trim(tokens[1]);
	item.price = stoi(trim(tokens[2]));
	vector<string> offersList = tokenize(trim(tokens[3]), '|');
	for (auto token : offersList) {
		tuple<int, Date, int> offer;
		tokens = tokenize(trim(token), ',');
		if (tokens.size() != 3)
			return is;
		int id = stoi(trim(tokens[0]));
		vector<string> dateTokens = tokenize(trim(tokens[1]), '-');
		if (dateTokens.size() != 3)
			return is;
		int day = stoi(trim(dateTokens[0]));
		int month = stoi(trim(dateTokens[1]));
		int year = stoi(trim(dateTokens[2]));
		Date date(day, month, year);
		int sum = stoi(trim(tokens[2]));
		offer = make_tuple(id, date, sum);
		item.offers.push_back(offer);
	}

	return is;
}

ostream& operator<<(ostream& os, const Item& item) {
	os << item.name << " ; " << item.category << " ; " << item.price;
	for (int index = 0; index < item.offers.size(); ++index) {
		os << get<0>(item.offers[index]) << ", " << get<1>(item.offers[index]).getDay() << "-" << get<1>(item.offers[index]).getMonth() << "-" << get<1>(item.offers[index]).getYear() << ", " << get<2>(item.offers[index]);
		if (index != item.offers.size() - 1)
			os << " | ";
	}
	return os;
}

string Item::toString() const {
	string output = name + " ; " + category + " ; " + to_string(price);
	return output;
}

string Item::toStringOffers() {
	string output;
	sort(offers.begin(), offers.end(), [](const tuple<int, Date, int>& a, const tuple<int, Date, int>& b) {
		return get<1>(a) > get<1>(b);
	});
	for (int index = 0; index < offers.size(); ++index) {
		output += to_string(get<0>(offers[index])) + " ; " + to_string(get<1>(offers[index]).getDay()) + "-" + to_string(get<1>(offers[index]).getMonth()) + "-" + to_string(get<1>(offers[index]).getYear()) + " ; " + to_string(get<2>(offers[index]));
		if (index != offers.size() - 1)
			output += '\n';
	}

	return output;
}
