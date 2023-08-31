/**************
 * Programmer: Isaac Denny
 * Course: CSC1720 Section 1
 * Date: August 31, 2023
 * Path: /home/students/idenny/csc1720/lab2/partc.cpp
 * Description: This program reads an input file and outputs a new pay table to the terminal and a file
 * Help received: None!
 * Compile: g++ partc.cpp
 * Execute: ./a.out
*************/


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

	outFile << left << setw(12) << "Last"  << setw(11) << "First" << setw(12) << "Old Pay" << setw(12) << "  New Pay" << endl;
	outFile << left << setw(12) << "-----------" << setw(11) << "---------" << setw(12) << "------------  " << setw(12) << "------------" << endl;
	outFile << fixed << showpoint << setprecision(2);

	cout << left << setw(12) << "Last" << setw(11) << "First" << setw(12) << "Old Pay" << setw(12) << "  New Pay" << endl;
	cout << left << setw(12) << "-----------" << setw(11) << "---------" << setw(12) << "------------  " << setw(12) << "------------" << endl;
	cout << fixed << showpoint << setprecision(2);


	while (!inFile.eof()) {
		inFile >> firstName;
		inFile >> lastName;
		inFile >> oldPay;
		
		double newPay = oldPay * 1.08f;
		outFile << left << setw(12) << lastName + "," << setw(11) << firstName << setw(12) << right << oldPay << setw(12) << newPay << endl;
		cout << left << setw(12) << lastName + "," << setw(11) << firstName << setw(12) << right << oldPay << setw(12) << newPay << endl;
	}

	inFile.close();
	outFile.close();
	return 0;
}