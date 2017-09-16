#pragma once
#include <string>
using namespace std;

class Card{
	int manacost; 
	string name;
	int dmg, hp;
	bool isDead, isCreture, isActive;
public:
	Card();
	Card(int, string);
	Card(int, string, int, int);
	int getManacost();
	void setManacost(int);
	string getName();
	void takeDmg(int);
	int getDmg();
	int getHp();
	bool dead();
	bool creature();
	bool active();
	void setActive(bool);
};


class CardEffect {
public:
	virtual void creatureEffect() = 0;
};

