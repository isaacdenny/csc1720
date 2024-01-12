#ifndef BOAT_H
#define BOAT_H

#include"Vehicle.h"
using namespace std;

class Boat : public Vehicle {
private:
	bool isFloating;
	double gasToNMRatio;
public:
	Boat(double mFuel);
	bool getIsFloating() { return isFloating; }
	void setIsFloating(bool f) { isFloating = f; }
	void showDash();
	void operate(double minutes, double speed);
};

#endif