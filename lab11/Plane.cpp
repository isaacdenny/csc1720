#include "Plane.h"

Plane::Plane(double mFuel) : Vehicle(mFuel), gasToMileRatio(200), altitude(4000)
{
}

void Plane::setAltitude(double a)
{
}

void Plane::showDash()
{
	cout << endl;
	cout << "Fuel (g): " << fuel << " - Distance (M): " << distance << " - Altitude (m): " << altitude << endl;
	cout << endl;
}

void Plane::operate(double minutes, double speed)
{
	double distancePossible = fuel * efficiency * gasToMileRatio;
	double temp = (speed / 60) * minutes;
	fuel -= temp / (efficiency * gasToMileRatio);
	if (temp >= distancePossible) {
		temp = distancePossible;
		fuel = 0;
	}
	distance += temp;
}
