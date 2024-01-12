#ifndef PLANE_H
#define PLANE_H

#include"Vehicle.h"

class Plane : public Vehicle {
private:
	double altitude;
	double gasToMileRatio;
public:
	Plane(double mFuel);
	double getAltitude() { return altitude; }
	void setAltitude(double a);
	void showDash();
	void operate(double minutes, double speed);
};

#endif