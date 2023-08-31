#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
	cout << fixed << showpoint << setprecision(2);
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

	outFile << left << setw(18) << "Last" << right << setw(8) << "First" << setw(10) << "Old Pay" << setw(10) << "New Pay" << endl;
	outFile << left << setw(18) << "--------------" << right << setw(8) << "-----" << setw(10) << "--------" << endl;

	while (!inFile.eof()) {
		inFile >> firstName;
		inFile >> lastName;
		inFile >> oldPay;
		
		double newPay = oldPay * 1.08f;
		outFile << left << setw(18) << lastName + "," << right << setw(8) << firstName << setw(10) << oldPay << setw(10) << newPay << endl;
	}

	inFile.close();
	outFile.close();
	return 0;
}