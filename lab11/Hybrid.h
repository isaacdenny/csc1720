#ifndef HYBRID_H
#define HYBRID_H

#include"Car.h"

class Hybrid : public Car {
private:
	double charge;
	double maxCharge;
	double mileToChargeRatio;
public:
	Hybrid(double mFuel, double mCharge);
	double getCharge() { return charge; }
	void setCharge(double c);
	void showDash();
	void operate(double minutes, double speed);
};

#endif
