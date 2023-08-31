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

	outFile << left << setw(12) << "Last"  << setw(12) << "First" << setw(12) << right << "Old Pay" << setw(12) << "New Pay" << endl;
	outFile << left << setw(12) << "-----------" << setw(12) << "---------" << setw(12) << right << "----------" << setw(12) << "----------" << endl;
	outFile << fixed << showpoint << setprecision(2);

	while (!inFile.eof()) {
		inFile >> firstName;
		inFile >> lastName;
		inFile >> oldPay;
		
		double newPay = oldPay * 1.08f;
		outFile << left << setw(12) << lastName + "," << setw(12) << firstName << setw(12) << right << oldPay << setw(12) << newPay << endl;
	}

	inFile.close();
	outFile.close();
	return 0;
}