#include<iostream>
#include"Hybrid.h"

using namespace std;

int main() {
	int fuel = 15, charge = 10;
	Hybrid h(fuel, charge);
	cout << "Drive data" << endl;
	h.addFuel(20);
	h.setCharge(20);
	h.showDash();
	h.operate(20, 60);
	h.showDash();
	cout << "----TEST 2------" << endl;
	h.operate(210, 60);
	h.showDash();
	cout << "----TEST 3------" << endl;
	h.operate(140, 60);
	h.showDash();
	cout << "----TEST 4------" << endl;
	h.operate(20, 60);
	h.setTirePressure(0);
	h.showDash();

	return 0;
}