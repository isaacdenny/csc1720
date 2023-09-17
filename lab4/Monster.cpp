#include "Monster.h"

Monster::Monster() :m_hp((rand() % 20) + 10), m_gold(0), m_strength((rand() % 15) + 10), m_name(getMonsterName()), m_isDead(false)
{
	
}

void Monster::takeDamage(int damage)
{
	lazyPrint("You hit" + m_name + "! It lost " + to_string(damage) + " hp!");
	m_hp -= damage;
	if (m_hp <= 0) {
		lazyPrint("Behold," + m_name + " died!");
		m_gold = (rand() % (m_strength * 2)) + m_strength;
		m_isDead = true;
	}
}

void Monster::showStats() {
	lazyPrint("Monster name:" + getName());
	lazyPrint("HP: " + to_string(getHP()));
	lazyPrint("Strength: " + to_string(getStrength()));
	cout << endl;
}