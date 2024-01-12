#include"Car.h"

Car::Car(double mFuel) : Vehicle(mFuel), mileToGasRatio(20), tirePressure(32), efficiency(1)
{
}

void Car::showDash()
{
	cout << endl;
	cout << "Fuel (g): " << fuel << " - Distance (M): " << distance << " - Tire Pressure: " << tirePressure << endl;
	cout << endl;
}

void Car::operate(double minutes, double speed)
{
	double gasPotential = fuel * efficiency * mileToGasRatio;
	double distToTravel = (speed / 60) * minutes;
	fuel -= distToTravel / (efficiency * mileToGasRatio);
	if (distToTravel >= gasPotential) {
		distToTravel = gasPotential;
		fuel = 0;
	}
	distance += distToTravel;
}