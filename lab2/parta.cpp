#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
	int num1;
	int num2;
	ifstream inFile;
	ofstream outFile;

	inFile.open("inputFile.txt");
	outFile.open("outputFile.txt");

	while (!inFile.eof()) {
		inFile >> num1;
		inFile >> num2;
		int sum = num1 + num2;
		cout << num1 << " + " << num2 << " = " << sum << endl;
	}

	inFile.close();
	outFile.close();
	return 0;
}