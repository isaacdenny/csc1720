#ifndef PLAYER_H
#define PLAYER_H
#include "helpers.h"

class Player {
private:
	string m_name;
	int m_startingHP;
	int m_hp;
	int m_gold;
	int m_strength;
	bool m_hasRested;
	bool m_isDead;
	string m_entrances[5] = {
		"You stumble into",
		"You jump into",
		"You fall into",
		"You run into",
		"You gracefully float into"
	};
public:
	Player();
	string getEntrance();
	string getName() { return m_name; }
	int getStartingHP() { return m_startingHP; }
	int getHP() { return m_hp; }
	int getStrength() { return m_strength; }
	int getGold() { return m_gold; }
	bool getIsDead() { return m_isDead; }
	bool getHasRested() { return m_hasRested; }
	void takeDamage(int damage);
	void addStrength(int strength);
	void addGold(int gold);
	void heal(int n);
	void showStats();
	void rest();
};

#endif