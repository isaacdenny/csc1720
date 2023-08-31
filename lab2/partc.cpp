#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
	string firstName;
	string lastName;
	double oldPay;
	ifstream inFile;
	ofstream outFile;
	string inputFileName;

	cout << "Input file: ";
	cin >> inputFileName;

	inFile.open(inputFileName);
	outFile.open("PayReport.txt");

	outFile << "Last First Old Pay New Pay";

	while (!inFile.eof()) {
		inFile >> firstName;
		inFile >> lastName;
		inFile >> oldPay;
		
		double newPay = oldPay * 1.08f;

		outFile << lastName + ", " + firstName << oldPay << newPay << endl;
	}

	inFile.close();
	outFile.close();
	return 0;
}