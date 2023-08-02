#pragma once

#include "Observer.h"

#include <vector>

using namespace std;

class Subject {
private:
	vector<Observer*> observers;
public:
	void registerObserver(Observer* observer);
	void unregisterObserver(Observer* observer);
	void notify();
};