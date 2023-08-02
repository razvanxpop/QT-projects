#pragma once
#include <string>
#include <vector>

using namespace std;

typedef struct DateAux {
private:
	int day;
	int month;
	int year;
public:
	DateAux() = default;
	DateAux(const int day, const int month, const int year) : day(day), month(month), year(year) {}

	int getDay() const { return day; }
	int getMonth()  const { return month; }
	int getYear() const { return year; }

	bool operator==(const DateAux& other) const {
		return this->day == other.day && this->month == other.month && this->year == other.year;
	}

	bool operator!=(const DateAux& other) const {
		return !(*this == other);
	}

	void operator=(const DateAux& other) {
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
	}

	bool operator<(const DateAux& other) const {
		if (this->year == other.year) {
			if (this->month == other.month) {
				if (this->day < other.day)
					return true;
			}
			else if (this->month < other.month) {
				return true;
			}
		}
		else if (this->year < other.year) {
			return true;
		}

		return false;
	}

	bool operator>(const DateAux &other) const {
		return (other < *this);
	}
} Date;

class Item {
private:
	string name;
	string category;
	int price;
	vector<tuple<int, Date, int>> offers;
public:
	Item() = default;
	Item(const string& name, const string& category, const int price, vector<tuple<int, Date, int>> offers) : name(name), category(category), price(price), offers(offers) {}

	string getName() const { return name; }
	string getCategory() const { return category; }
	int getPrice() const { return price; }
	vector<tuple<int, Date, int>>& getOffers() { return offers; }

	void setPrice(const int newPrice) { price = newPrice; }
	void addOffer(const tuple<int, Date, int> offer) { offers.push_back(offer); }

	friend istream& operator>>(istream& is, Item& item);
	friend ostream& operator<<(ostream& os, const Item& item);

	string toString() const;
	string toStringOffers();

	bool operator==(const Item& other) const {
		return this->name == other.name && this->category == other.category && this->price == other.price;
	}

	bool operator!=(const Item& other) const {
		return !(*this == other);
	}
};