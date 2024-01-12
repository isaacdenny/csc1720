#ifndef CAR_H
#define CAR_H

#include"Vehicle.h"

class Car : public Vehicle {
public:
	Car(double mFuel);
	double efficiency;
	double mileToGasRatio;
	double tirePressure;
	double getTirePressure() { return tirePressure; }
	void setTirePressure(double tp) { tirePressure = tp; }
	void showDash();
	void operate(double minutes, double speed);
};

#endif