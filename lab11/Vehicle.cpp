#include "Vehicle.h"

Vehicle::Vehicle(double mFuel) : maxFuel(mFuel), fuel(0), efficiency(0.95), distance(0)
{
}

void Vehicle::addFuel(double f)
{
	if (f <= 0)
		return;
	fuel = fuel + f > maxFuel ? maxFuel : fuel + f;
}

void Vehicle::setFuel(double f)
{
	fuel = f > maxFuel ? maxFuel : f;
}

void Vehicle::setDistance(double d)
{
	distance = d;
}
