#ifndef MONSTER_H
#define MONSTER_H
#include "helpers.h"
using namespace std;

class Monster {
private:
	int m_hp;
	int m_strength;
	int m_gold;
	bool m_isDead;
	string m_name;
public:
	Monster();
	int getHP() { return m_hp; }
	int getStrength() { return m_strength; }
	int getGold() { return m_gold; }
	string getName() { return m_name; }
	bool getIsDead() { return m_isDead; }
	void takeDamage(int damage);
	void showStats();
};
#endif // !MONSTER_H
