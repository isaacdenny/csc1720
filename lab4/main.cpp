/**************
 * Programmer: Isaac Denny
 * Course: CSC1720 Section 1
 * Date: September 17, 2023
 * Path: /home/students/idenny/csc1720/lab4/main.cpp
 * Description: This is Super RPS! Play against the computer.
 * Help received: None!
 * Compile (Windows): g++ -std=c++11 main.cpp Dungeon.cpp Room.cpp Player.cpp helpers.cpp Monster.cpp -o linearlabyrinth.exe
 * Execute (Windows): ./linearlabyrinth.exe
 * Compile (Linux): g++ -std=c++11 main.cpp Dungeon.cpp Room.cpp Player.cpp helpers.cpp Monster.cpp -o linearlabyrinth.out
 * Execute (Linux): ./linearlabyrinth.out
*************/

#include <fstream>
#include "Dungeon.h"

using namespace std;

void printExposition(string pname);
void showCommands(bool isEndgame = false, bool hasReturned = false, bool hasRested = false);
void finishGame(Player* p, int nRooms);

int main(int argc, char* argv[]) {
	srand(time(NULL));
	bool justEntered = false;
	bool justStarted = true;
	bool isEndGame = false;
	bool justReturned = false;
	bool hasReturned = false;

	Player* player = new Player();
	Dungeon* dungeon = new Dungeon();

	printExposition(player->getName());
	char input = 'c';

	// game loop
	while (input != 113) {
		switch (input) {
			case 109:
				if (!dungeon->getIsEndgame()) {
					player->addGold((rand() % 5) + 3);
					dungeon->moveNextRoom();
					justEntered = true;
				}
				break;
			case 114:
				if (dungeon->getIsEndgame()) {
					finishGame(player, dungeon->getNumRooms());
					return 0;
				}
				if (player->getHasRested()) {
					lazyPrint("You have already rested! Focus on the task at hand!", 20);
					cout << endl;
				}
				else {
					player->rest();
					dungeon->setRestRoom();
				}
				break;
			case 99:
				showCommands(dungeon->getIsEndgame(), hasReturned, player->getHasRested());
				break;
			case 115:
				player->showStats();
				break;
			case 103:
				if (dungeon->getIsEndgame() && player->getHasRested() && !hasReturned) {
					dungeon->returnToRestRoom();
					justReturned = true;
					hasReturned = true;
				}
				else if (!dungeon->getIsEndgame()) {
					lazyPrint("Error, please enter a valid command!");
					showCommands(dungeon->getIsEndgame(), hasReturned, player->getHasRested());
				} // try to remove
				break;
			default:
				lazyPrint("Error, please enter a valid command!");
				showCommands(dungeon->getIsEndgame(), hasReturned, player->getHasRested());
				break;
		}

		if (dungeon->getCurrentRoom()->getIsBattleRoom()) {
			dungeon->startBattle(player);
		}

		if (player->getIsDead()) {
			finishGame(player, dungeon->getNumRooms());
			return 0;
		}
		else if (justStarted) {
			lazyPrint("Waking up, you realize you are in", 20, false);
			justStarted = false;
		}
		else if (justReturned) {
			lazyPrint("You returned to", 20, false);
			justReturned = false;
		}
		else if (justEntered) {
			lazyPrint(player->getEntrance(), 20, false);
			justEntered = false;
		}
		else {
			lazyPrint("You are in", 20, false);
		}

		lazyPrint(dungeon->getCurrentRoom()->getMessage(), 20);
		cout << endl;


		if (dungeon->getIsEndgame()) {
			showCommands(dungeon->getIsEndgame(), hasReturned, player->getHasRested());
		}
		lazyPrint(player->getName() + ", what will you do? [c]ommand list: ", 20, false);
		cin >> input;
		cout << endl;
	}

	// game ended
	finishGame(player, dungeon->getNumRooms());
	return 0;
}

void printExposition(string pname) {
	lazyPrint("Welcome to the Linear Labyrinth, " + pname + "...");
	lazyPrint("As your eyes adjust, you see that you can only go forward...", 20);
	lazyPrint("If you rest, you may return to that room once you reach the end.", 20);
	lazyPrint("You may rest ONLY ONCE!", 100);
	cout << endl;
}

void showCommands(bool isEndGame, bool hasReturned, bool hasRested) {
	if (isEndGame) {
		if (!hasReturned && hasRested) {
			lazyPrint("[G]o back to the room you rested in", 20);
		}
		lazyPrint("[R]each into the light", 20);
	}
	else {
		lazyPrint("[M]ove to the next room", 20);
		if (!hasRested) {
			lazyPrint("[R]est here for a while", 20);
		}
	}
	lazyPrint("[S]how player stats", 20);
	lazyPrint("[Q]uit game", 20);
	cout << endl;
}

void finishGame(Player* p, int nRooms) {
	if (!p->getIsDead()) {
		lazyPrint("You have reached out into the light at the end of the labyrinth", 20, false);
		lazyPrint("...", 500);
		lazyPrint("You feel at peace.", 50);
		cout << endl;
		lazyPrint("You made it out of the Linear Labyrinth!");
		cout << endl;
	}
	else {
		lazyPrint("You never made it out of the labyrinth", 20, false);
		lazyPrint("...", 500);
		lazyPrint("You feel upset.", 50);
		cout << endl;
		lazyPrint("You should probably try again...");
		cout << endl;
	}
	p->showStats();

	ofstream out;
	ifstream in;

	out.open("highscores.txt", ios::out | ios_base::app);

	int h = p->getHP();
	int s = p->getStrength();
	int g = p->getGold();
	int score = h * s * g * nRooms;

	out << "Player name: " + p->getName() + "\n";
	out << "HP: " + to_string(h) + "\n";
	out << "Strength: " + to_string(s) + "\n";
	out << "Gold: " + to_string(g) + "\n";
	out << "Total Score: " + to_string(score) + "\n\n";
	out.close();

	in.open("highscores.txt");
	lazyPrint("High Scores: ");
	cout << endl;
	string line;
	while (getline(in, line)) {
		lazyPrint(line);
	}
}