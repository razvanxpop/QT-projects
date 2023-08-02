#pragma once
#include <string>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date() = default;
	Date(int day, int month, int year) : day(day), month(month), year(year) {}
	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }

	void setDay(int newDay) { day = newDay; }
	void setMonth(int newMonth) { month = newMonth; }
	void setYear(int newYear) { year = newYear; }

	bool operator<(const Date& other) {
		if (this->year < other.year) {
			return true;
		}
		else if(this->year == other.year && this->month < other.month){
			return true;
		}
		else if (this->year == other.year && this->month == other.month && this->day < other.day) {
			return true;
		}

		return false;
	}

	bool operator>(Date& other) {
		return other < *this;
	}

	bool operator==(const Date& other) {
		return this->year == other.year && this->month == other.month && this->day == other.day;
	}

	bool operator!=(const Date& other) {
		return !(*this == other);
	}

	void operator=(const Date& other) {
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
	}
};

class Patient {
private:
	string name;
	string diagnosis;
	string specialization;
	string doctor;
	Date date;
public:
	Patient() : diagnosis("undiagnosed"), specialization("") {}
	Patient(const string& name, const string& diagnosis, const string& specialization, const string& doctor, const Date& date);

	string getName() const { return name; }
	string getDiagnosis() const { return diagnosis; }
	string getSpecialization() const { return specialization; }
	string getDoctor() const { return doctor; }
	Date getDate() const { return date; }

	void setDiagnosis(const string& newDiagnosis) { diagnosis = newDiagnosis; }
	void setSpecialization(const string& newSpecialization) { specialization = newSpecialization; }
	void setDoctor(const string& newDoctor) { doctor = newDoctor; }

	friend istream& operator>>(istream& is, Patient& patient);
	friend ostream& operator<<(ostream& os, const Patient& patient);

	string toString() const;

	bool operator==(const Patient& other) {
		return this->name == other.name && this->diagnosis == other.diagnosis && this->specialization == other.specialization && this->doctor == other.doctor && this->date == other.date;
	}

	bool operator!=(const Patient& other) {
		return !(*this == other);
	}
};