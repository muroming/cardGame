#include "stdafx.h"
#include "Card.h"
#include <string>

using namespace std;


Card::Card() {}
//Init for spells
Card::Card(int m, string n) :manacost(m) {
	name = n;
	isCreture = false;
}

//Init for creatures
Card::Card(int m, string n, int h, int d) {
	manacost = m;
	name = n;
	hp = h;
	dmg = d;
	isCreture = true;
	isDead = false;
}
int Card::getManacost() {
	return manacost;
}
void Card::setManacost(int m) {
	manacost = m;
}
string Card::getName() {
	return name;
}

int Card::getHp() {
	if (isCreture) {
		return hp;
	}
}

bool Card::dead() {
	if (isCreture) {
		return isDead;
	}
}

int Card::getDmg() {
	if (isCreture) {
		return dmg;
	}
}

void Card::takeDmg(int d) {
	if (isCreture) {
		if (hp > d) {
			hp -= d;
		}
		else {
			hp = 0;
			isDead = true;
		}
	}
}

bool Card::creature() {
	return isCreture;
}