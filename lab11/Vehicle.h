#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>

using namespace std;

class Vehicle {
public:
	double fuel;
	double maxFuel;
	double distance;
	double efficiency;
	Vehicle(double mFuel);
	void addFuel(double f);
	double getFuel() { return fuel; }
	void setFuel(double f);
	double getDistance() { return distance; }
	void setDistance(double d);
	virtual void showDash() = 0;
	virtual void operate(double minutes, double speed) = 0;
};

#endif