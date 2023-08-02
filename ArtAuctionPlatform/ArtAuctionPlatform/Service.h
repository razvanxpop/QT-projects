#pragma once
#include "Subject.h"
#include "Repository.h"

class Service : public Subject {
private:
	Repository& repository;
public:
	Service(Repository& repository) : repository(repository) {}

	vector<Item>& getItems() { return repository.getItems(); }
	vector<Item> getItemsByCategory(const string& category);

	Item findItem(const string& itemString);
	void addItem(const string& name, const string& category, const int price);
	void bidItem(const string& itemString, const int bidPrice, const int userId);
};