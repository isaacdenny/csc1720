/**************
 * Programmer: Isaac Denny
 * Course: CSC1720 Section 1
 * Date: September 7, 2023
 * Path: /home/students/idenny/csc1720/lab3/rps.cpp
 * Description: This is Super RPS! Play against the computer.
 * Help received: None!
 * Compile: g++ rps.cpp -o rps.out
 * Execute: ./rps.out
*************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
	string items[] = { "scissors", "paper", "rock", "lizard", "spock" };
	string input = "";

	cout << "*** Welcome to Super RPS *** \n";
	cout << "Would you like to play? (y or n)? ";
	cin >> input;
	while (input != "n" && input != "y") {
		cout << "Invalid input!";
		cout << "Would you like to play? (y or n)? ";
		cin >> input;
	}

	while (input != "n") {
		cout << "Rock! Paper! Scissors! Shoot!!!\n";
		cout << "Choose an item (r, p, s, l, or k): ";
		cin >> input;

		int player = 0;
		int comp = rand() % 5;

		if (input == "r") {
			cout << "You chose rock! ";
			player = 2;
		}
		else if (input == "p") {
			cout << "You chose paper! ";
			player = 1;
		}
		else if (input == "s") {

			cout << "You chose scissors! ";
			player = 0;
		}
		else if (input == "l") {
			cout << "You chose lizard! ";
			player = 3;
		}
		else if (input == "k") {
			cout << "You chose spock! ";
			player = 4;
		}
		else {
			cout << "Invalid choice!\n";
			continue;
		}

		cout << "The computer chose " << items[comp] << "! ";

		string result = "";
		if (player == comp) {
			result = "It's a tie!\n";
		}
		else if (player - comp == -2) {
			result = "The computer wins!\n";
		}
		else if (player - comp == 2) {
			result = "You win!\n";
		}
		else if (player == 0 && comp == 4) {
			result = "The computer wins!\n";
		}
		else if (player == 4 && comp == 0) {
			result = "You win!\n";
		}
		else if (player > comp) {
			result = "The computer wins!\n";
		}
		else if (player < comp) {
			result = "You win!\n";
		}

		cout << result;
		cout << "Would you like to play again? (y or n)? ";
		cin >> input;
		while (input != "n" && input != "y") {
			cout << "Invalid input!";
			cout << "Would you like to play? (y or n)? ";
			cin >> input;
		}
	}
	cout << "Thanks for playing!\n";
	return 0;
}