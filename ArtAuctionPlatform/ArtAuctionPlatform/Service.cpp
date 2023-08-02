#include "Service.h"
#include "utils.h"

#include <algorithm>
#include <iterator>
#include <ctime>

vector<Item> Service::getItemsByCategory(const string& category) {
	vector<Item> filteredItems;
	vector<Item> items = repository.getItems();
	copy_if(items.begin(), items.end(), back_inserter(filteredItems), [category](const Item& item) {
		return item.getCategory() == category;
	});

	return filteredItems;
}

Item Service::findItem(const string& itemString) {
	vector<string> tokens = tokenize(trim(itemString), ';');
	string name = trim(tokens[0]);
	string category = trim(tokens[1]);
	int price = stoi(trim(tokens[2]));
	vector<tuple<int, Date, int>> offers;
	Item item(name, category, price, offers);
	vector<Item> items = repository.getItems();
	auto it = find(items.begin(), items.end(), item);
	return *it;
}

void Service::addItem(const string& name, const string& category, const int price) {
	vector<tuple<int, Date, int>> offers;
	Item item(name, category, price, offers);
	repository.addItem(item);
	this->notify();
}

void Service::bidItem(const string& itemString, const int bidPrice, const int userId) {
	vector<string> tokens = tokenize(trim(itemString), ';');
	int oldPrice = stoi(trim(tokens[2]));
	if (oldPrice >= bidPrice)
		throw runtime_error("The offered sum is not greater than the current price!");
	string name = trim(tokens[0]);
	string category = trim(tokens[1]);
	vector<tuple<int, Date, int>> offers;
	Item item(name, category, oldPrice, offers);
	tuple<int, Date, int> offer;
	get<0>(offer) = userId;
	time_t currentTime = time(nullptr);
	tm* localTime = localtime(&currentTime);
	int year = localTime->tm_year + 1900;
	int month = localTime->tm_mon + 1;
	int day = localTime->tm_mday;
	Date date(day, month, year);
	get<1>(offer) = date;
	get<2>(offer) = bidPrice;
	repository.bidItem(item, bidPrice, offer);
	this->notify();
}
