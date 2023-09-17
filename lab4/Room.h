#ifndef ROOM_H
#define ROOM_H
#include "helpers.h"

class Room {
private:
	string m_message;
	Room* m_nextRoom;
	bool m_isBattleRoom;
public:
	Room(Room* n);
	string getMessage() { return m_message; }
	Room* getNextRoom() { return m_nextRoom; }
	bool getIsBattleRoom() { return m_isBattleRoom; }
	void setNextRoom(Room* r);
	void setBattleRoom();
	void setRoomDesc(string d);
};

#endif