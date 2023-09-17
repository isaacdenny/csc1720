#include "Player.h"

Player::Player() :m_name(""), m_hp(20), m_startingHP(20), m_gold(0), m_strength(10), m_isDead(false), m_hasRested(false)
{
	cout << endl;
	lazyPrint("What is your name? ", 70, false);
	cin >> m_name;
}

string Player::getEntrance()
{
	int n = sizeof(m_entrances) / sizeof(m_entrances[0]);
	return m_entrances[rand() % n];
}

void Player::takeDamage(int damage)
{
	m_hp -= damage;
	lazyPrint("You got hit! -" + to_string(damage) + " hp!");
	if (m_hp <= 0) {
		lazyPrint("You died...", 300);
		m_isDead = true;
	}
}

void Player::addGold(int gold) 
{
	m_gold += gold;
	if (gold > 0) {
		lazyPrint("You got +" + to_string(gold) + " gold!");
	}
	else {
		lazyPrint("You lost " + to_string(gold) + " gold!");
	}
}

void Player::heal(int n)
{
	m_hp += n;
	lazyPrint("You healed +" + to_string(n) + " hp!");
	if (m_hp == m_startingHP) {
		lazyPrint("You are at full HP!");
	}
}

void Player::addStrength(int s) 
{
	m_strength += s;
	if (s > 0) {
		lazyPrint("You got +" + to_string(s) + " strength!");
	}
	else {
		lazyPrint("You lost " + to_string(s) + " strength!");
	}
}

void Player::showStats() {
	lazyPrint("Player name: " + getName());
	lazyPrint("HP: " + to_string(getHP()));
	lazyPrint("Strength: " + to_string(getStrength()));
	lazyPrint("Gold: " + to_string(getGold()));
	cout << endl;
}

void Player::rest() {
	lazyPrint("You rest for a while", 40, false);
	lazyPrint("...", 500);
	addStrength(10);
	heal(m_startingHP - m_hp);
	addGold(10);
	lazyPrint("You've awoken!");
	lazyPrint("If you so wish, you may return to this room at the end of the labyrinth.");
	cout << endl;

	m_hasRested = true;
}