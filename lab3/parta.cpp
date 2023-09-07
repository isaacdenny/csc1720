#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int rollDice() {
	return rand() % 6 + 1;
}

int main() {
	string input = "";
	cout << "Would you like to play Dice (y or n)? ";
	cin >> input;
	while (input != "n") {
		int num1 = rollDice();
		int num2 = rollDice();
		int num3 = rollDice();
		int num4 = rollDice();

		cout << "You roll: " << num1 << " and " << num2 << endl;
		cout << "The computer rolls " << num3 << " and " << num4 << endl;

		string result = "";
		if (num1 == num2 && num3 != num4) {
			result = "You win!\n";
		}
		else if (num3 == num4 && num1 != num2) {
			result = "The computer wins!\n";
		}
		else if (num1 == num2 && num3 == num4) {
			if (num1 > num3) {
				result = "You win!\n";
			}
			else if (num1 == num3) {
				result = "It's a tie!\n";
			}
			else {
				result = "The computer wins!\n";
			}
		}
		else if (num1 + num2 == num3 + num4) {
			result = "It's a tie!\n";
		}
		else if (num1 + num2 > num3 + num4) {
			result = "You win!\n";
		}
		else {
			result = "The computer wins!\n";
		}
	}
	cout << "Thanks for playing!\n";
	return 0;
}
