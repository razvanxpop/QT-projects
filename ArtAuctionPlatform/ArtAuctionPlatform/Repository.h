#pragma once
#include "User.h"
#include "Item.h"

class Repository {
private:
	vector<User> users;
	vector<Item> items;
	string usersFile;
	string itemsFile;
public:
	Repository(const string& usersFile, const string& itemsFile);

	User* getUser(int index) { return &users[index]; }
	vector<Item>& getItems() { return items; }
	vector<User>& getUsers() { return users; }

	void addItem(const Item& item);
	void bidItem(const Item& item, const int bidPrice, const tuple<int, Date, int> offer);

private:
	void loadUsers();
	void loadItems();
	void saveItems();
};