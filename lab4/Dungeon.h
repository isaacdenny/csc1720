#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"
#include "Player.h"
#include "Monster.h"
#include "helpers.h"

class Dungeon {
private:
	int m_numRooms;
	float m_battleChance;
	Room* m_currentRoom;
	Room* m_restRoom;
	bool m_isEndGame;
public:
	Dungeon();
	void moveNextRoom();
	int getNumRooms() { return m_numRooms; }
	Room* getCurrentRoom() { return m_currentRoom; }
	bool getIsEndgame() { return m_isEndGame; }
	void setRestRoom();
	void returnToRestRoom();
	void startBattle(Player* p);
	void showBattleCommands(bool hasHealed);
};

#endif
