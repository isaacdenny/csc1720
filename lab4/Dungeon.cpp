#include "Dungeon.h"

Dungeon::Dungeon() :m_numRooms(2), m_restRoom(nullptr)
{
	lazyPrint("How many rooms should the labyrinth have? (min 5, max 15): ", 40, false);
	cin >> m_numRooms;
	while (m_numRooms > 15 || m_numRooms < 5) {
		cin.clear();
		cin.ignore(1000, '\n');
		lazyPrint("Sorry, you must choose more than 4, and less than 16");
		lazyPrint("How many rooms should the labyrinth have? (min 5, max 15): ", 40, false);
		cin >> m_numRooms;
		cout << endl;
	}

	Room* r = new Room(nullptr);
	m_currentRoom = r;
	m_battleChance = 4 * static_cast<float>(100) / m_numRooms;

	for (size_t i = 1; i < m_numRooms; i++)
	{
		Room* newRoom = new Room(nullptr);
		if (i == m_numRooms - 1) {
			newRoom->setRoomDesc(" the final room. You can see a light ahead.");
		}
		else if (rand() % 100 <= m_battleChance) {
			newRoom->setBattleRoom();
		}
		r->setNextRoom(newRoom);
		r = newRoom;
	}
}


void Dungeon::startBattle(Player* p) {
	Monster* m = new Monster();
	bool hasHealed = false;
	char input = 'c';
	float hitChance;

	lazyPrint("*** Start Battle ***");
	while (input != 113) {
		switch (input) {
			case 102:
				hitChance = p->getStrength() / (static_cast<float>(p->getStrength()) + m->getStrength());
				if (rand() % 100 < hitChance * 100) {
					m->takeDamage(p->getStrength());
				}
				else {
					p->takeDamage(m->getStrength());
				}
				break;
			case 104:
				if (!hasHealed) {
					p->heal(10);
					hasHealed = true;
				}
				else {
					lazyPrint("You already healed this battle...");
				}
				break;
			case 114: 
				lazyPrint("You ran from battle!");
				lazyPrint("Behold," + m->getName() + " hit you as you ran...");
				p->takeDamage((m->getStrength() % 5) + 1);
				moveNextRoom();
				return;
				break;
			case 99:
				showBattleCommands(hasHealed);
				break;
			case 115:
				p->showStats();
				break;
			case 109:
				m->showStats();
				break;
			default:
				lazyPrint("Error, please enter a valid command!");
				showBattleCommands(hasHealed);
				break;
		}
		if (m->getIsDead()) {
			lazyPrint("*** You Won ***");
			p->addGold(m->getGold());
			m_currentRoom->setBattleRoom();
			return;
		}
		else if (p->getIsDead()) {
			return;
		}

		lazyPrint("Behold," + m->getName() + " stands before you!", 10);
		cout << endl;
		lazyPrint(p->getName() + ", what will you do? [c]ommand list: ", 20, false);
		cin >> input;
		cout << endl;
	}
}

void Dungeon::moveNextRoom() {
	lazyPrint("You move on to the next room...", 20);
	Room* r = m_currentRoom->getNextRoom();
	m_currentRoom = r;
	if (m_currentRoom->getNextRoom() == nullptr) {
		m_isEndGame = true;
	}
}

void Dungeon::returnToRestRoom() {
	m_currentRoom = m_restRoom;
	m_isEndGame = false;
}

void Dungeon::setRestRoom() {
	m_restRoom = m_currentRoom;
}

void Dungeon::showBattleCommands(bool hasHealed) {
	lazyPrint("[F]ight", 20);
	if (!hasHealed) {
		lazyPrint("[H]eal", 20);
	}
	lazyPrint("[R]un", 20);
	lazyPrint("[S]how player stats", 20);
	lazyPrint("[M]onster stats", 20);
	lazyPrint("[Q]uit game", 20);
	cout << endl;
}

