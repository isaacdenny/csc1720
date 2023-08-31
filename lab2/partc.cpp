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

	outFile << left << setw(12) << "Last"  << setw(8) << "First" << setw(10) << right << "Old Pay" << setw(10) << "New Pay" << endl;
	outFile << left << setw(12) << "-----------" << setw(8) << "-----" << setw(10) << right << "--------" << setw(10) << "--------" << endl;
	outFile << fixed << showpoint << setprecision(2);

	while (!inFile.eof()) {
		inFile >> firstName;
		inFile >> lastName;
		inFile >> oldPay;
		
		double newPay = oldPay * 1.08f;
		outFile << left << setw(12) << lastName + "," << setw(8) << firstName << setw(10) << right << oldPay << setw(10) << newPay << endl;
	}

	inFile.close();
	outFile.close();
	return 0;
}