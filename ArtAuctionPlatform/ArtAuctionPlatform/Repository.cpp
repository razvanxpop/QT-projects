#include "Repository.h"

#include <fstream>

Repository::Repository(const string& usersFile, const string& itemsFile) {
	this->usersFile = usersFile;
	this->itemsFile = itemsFile;
	loadUsers();
	loadItems();
}

void Repository::addItem(const Item& item) {
	auto it = find(items.begin(), items.end(), item);
	if (it == items.end()) {
		items.push_back(item);
		saveItems();
		return;
	}
	throw runtime_error("The item already exists!");
}

void Repository::bidItem(const Item& item, const int bidPrice, const tuple<int, Date, int> offer) {
	auto it = find(items.begin(), items.end(), item);
	if (it != items.end()) {
		it->setPrice(bidPrice);
		it->addOffer(offer);
		saveItems();
		return;
	}
	throw runtime_error("The selected item no longer exists!");
}

void Repository::loadUsers() {
	ifstream fin(usersFile);
	if (!fin.is_open())
		throw runtime_error("Could not open the users file for reading!");
	User user;
	while (fin >> user)
		users.push_back(user);
	fin.close();
}

void Repository::loadItems() {
	ifstream fin(itemsFile);
	if (!fin.is_open())
		throw runtime_error("Could not open the items file for reading!");
	while (!fin.eof()) {
		Item item;
		fin >> item;
		items.push_back(item);
	}

	fin.close();
}

void Repository::saveItems() {
	ofstream fout(itemsFile);
	if (!fout.is_open())
		throw runtime_error("Could not open the items file for writing!");
	for (auto item : items)
		fout << item << '\n';

	fout.close();
}
