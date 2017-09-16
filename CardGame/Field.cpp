#include "stdafx.h"
#include <iostream>
#include "Card.h"
#include "Field.h"
#define maxCreatures 10

int Field::getPlayerOneTotal() {
	return playerOneTotal;
}

int Field::getPlayerTwoTotal() {
	return playerTwoTotal;
}

Card* Field::getCreature(int num, int player) {
	if (player == 1) {
		return playerOneCreatures[num - 1];
	}
	if (player == 2) {
		return playerTwoCreatures[num - 1];
	}
	return nullptr;
}

void Field::creaturesCheck() {
	for (int i = 0; i < playerOneTotal; i++) {
		if (playerOneCreatures[i]->getHp() <= 0) {
			destroyCreature(playerOneCreatures[i]);
		}
	}
	for (int i = 0; i < playerTwoTotal; i++) {
		if (playerTwoCreatures[i]->getHp() <= 0) {
			destroyCreature(playerTwoCreatures[i]);
		}
	}
}

Card** Field::getPlayerOneCreatures() {
	return playerOneCreatures;
}

Card** Field::getPlayerTwoCreatures() {
	return playerTwoCreatures;
}

bool Field::creaturesFight(Card* attacking, Card* defending) {
	if (attacking->active()) {
		defending->takeDmg(attacking->getDmg());
		attacking->takeDmg(defending->getDmg());
		attacking->setActive(false);
		if (defending->dead()) {
			destroyCreature(defending);
		}
		if (attacking->dead()) {
			destroyCreature(attacking);
		}
		return true;
	}
	cout << "Chosen creature is not active\n";
	return false;
}

void Field::activeAll(int player) {
	if (player == 1) {
		for (int i = 0; i < playerOneTotal; i++) {
			playerOneCreatures[i]->setActive(true);
		}
	}
	else {
		for (int i = 0; i < playerTwoTotal; i++) {
			playerTwoCreatures[i]->setActive(true);
		}
	}
}

void Field::destroyCreature(Card* card) {
	for (int i = 0; i < playerOneTotal; i++) {
		if (playerOneCreatures[i] == card) {
			for (int j = i; j <= playerOneTotal - 1; j++) {
				playerOneCreatures[j] = playerOneCreatures[j + 1];
			}
			delete card;
			playerOneTotal--;
			return;
		}
	}
	for (int i = 0; i < playerTwoTotal; i++) {
		if (playerTwoCreatures[i] == card) {
			for (int j = i; j <= playerTwoTotal - 1; j++) {
				playerTwoCreatures[j] = playerTwoCreatures[j + 1];
			}
			delete card;
			playerTwoTotal--;
			return;
		}
	}
}

Field::Field() {
	playerOneCreatures = new Card*[maxCreatures];
	playerTwoCreatures = new Card*[maxCreatures];
	playerOneTotal = playerTwoTotal = 0;
}

bool Field::addCreature(Card* c, int playerNum) {
	if (playerNum == 1) {
		if (playerOneTotal < maxCreatures) {
			playerOneCreatures[playerOneTotal++] = c;
			return true;
		}
		cout << "Too many creatures\n";
		return false;
	}
	if (playerNum == 2) {
		if (playerOneTotal < maxCreatures) {
			playerTwoCreatures[playerTwoTotal++] = c;
			return true;
		}
		return false;
		cout << "Too many creatures\n";
	}
	return false;
}

