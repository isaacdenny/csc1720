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
	string[] items = { "scissors", "paper", "rock", "lizard", "spock" };
	string input = "";

	cout << "*** Welcome to Super RPS *** ";
	cout << "Would you like to play? (y or n)? ";
	cin >> input;

	while (input != "n") {
		cout << "Rock! Paper! Scissors! Shoot!!!";
		cout << "Choose an item (r, p, s, l, or p): ";
		cin >> input;

		int player = 0;
		int comp = rand() % items.length;

		switch (input) {
			case "r":
				cout >> "You chose rock!";
				player = 0;
				break;
			case "p":
				cout >> "You chose paper!";
				player = 1;
				break;
			case "s":
				cout >> "You chose scissors!";
				player = 2;
				break;
			case "l":
				cout >> "You chose lizard!";
				player = 3;
				break;
			case "p":
				cout >> "You chose spock!";
				player = 4;
				break;
			default:
				cout << "Invalid choice!";
				continue;
				break;
		}

		cout << "The computer chose " << items[comp];

		string result = "";
		if (player == comp) {
			result = "It's a tie!";
		}
		else if (player > comp) {
			result = "The computer wins!";
		}
		else if (player < comp) {
			result = "You win!";
		}

		cout << result;
	}
	cout << "Thanks for playing!";
	return 0;
}