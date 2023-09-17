#include "Room.h"

Room::Room(Room* n) :m_message(getRoomDesc()), m_nextRoom(n), m_isBattleRoom(false)
{
}

void Room::setNextRoom(Room* r)
{
	m_nextRoom = r;
}

void Room::setBattleRoom() {
	m_isBattleRoom = !m_isBattleRoom;
}

void Room::setRoomDesc(string d) {
	m_message = d;
}
