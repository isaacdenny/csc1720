#include "Hybrid.h"

Hybrid::Hybrid(double mFuel, double mCharge) : Car(mFuel), maxCharge(mCharge), charge(0), mileToChargeRatio(3)
{
}

void Hybrid::setCharge(double c)
{
	charge = c;
	if (c > maxCharge)
		charge = maxCharge;
}

void Hybrid::showDash()
{
	cout << endl;
	cout << "Fuel (g): " << fuel << " - Charge (kWH): " << charge << " - Distance (M): " << distance << " - Tire Pressure: " << tirePressure << endl;
	cout << endl;
}

void Hybrid::operate(double minutes, double speed)
{
	double chargePotential = charge * efficiency * mileToChargeRatio;
	double gasPotential = fuel * efficiency * mileToGasRatio;
	double distToTravel = (speed / 60) * minutes;
	double distTravelledOnGas = 0;
	double distTravelledOnCharge = 0;

	charge -= distToTravel / (efficiency * mileToChargeRatio);
	distTravelledOnCharge = distToTravel;

	if (distToTravel >= chargePotential) {
		distTravelledOnCharge = chargePotential;
		charge = 0;
	}

	double distLeft = distToTravel - distTravelledOnCharge;
	if (distLeft > 0) {
		fuel -= distLeft / (efficiency * mileToGasRatio);
		distTravelledOnGas = distLeft;
		if (distLeft >= gasPotential) {
			distTravelledOnGas = gasPotential;
			fuel = 0;
		}
		charge = distTravelledOnGas * 0.1 > maxCharge ? maxCharge : distTravelledOnGas * 0.1;
	}

	distLeft = distToTravel - distTravelledOnCharge - distTravelledOnGas;

	chargePotential = charge * efficiency * mileToChargeRatio;
	if (distLeft > 0 && distLeft >= chargePotential) {
		distTravelledOnCharge += chargePotential;
		charge = 0;
	}
	else if (distLeft > 0) {
		distTravelledOnCharge += distLeft;
		charge -= distLeft / (efficiency * mileToChargeRatio);
	}

	distance += distTravelledOnCharge + distTravelledOnGas;
}
