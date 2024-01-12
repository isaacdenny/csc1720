#include "Boat.h"

Boat::Boat(double mFuel) : Vehicle(mFuel), gasToNMRatio(20), isFloating(true)
{
}

void Boat::showDash()
{
	cout << endl;
	cout << "Fuel (g): " << fuel << " - Distance (NM): " << distance << " - Floating: " << isFloating << endl;
	cout << endl;
}

void Boat::operate(double minutes, double speed)
{
	double distancePossible = fuel * efficiency * gasToNMRatio;
	double temp = (speed / 60) * minutes;
	fuel -= temp / (efficiency * gasToNMRatio);
	if (temp >= distancePossible) {
		temp = distancePossible;
		fuel = 0;
	}
	distance += temp;
}
