#include "stdafx.h"
#include <string>
#include "Card.h"
#include "Field.h"
#define maxCreatures 10

int Field::getPlayerOneTotal() {
	return playerOneTotal;
}

int Field::getPlayerTwoTotal() {
	return playerTwoTotal;
}

Card** Field::getPlayerOneCreatures() {
	return playerOneCreatures;
}

Card** Field::getPlayerTwoCreatures() {
	return playerTwoCreatures;
}

void Field::creaturesFight(Card* attacking, Card* defending) {
	defending->takeDmg(attacking->getDmg());
	if (defending->dead()) {
		destroyCreature(defending);
	}
}

void Field::destroyCreature(Card* card) {
	for (int i = 0; i < playerOneTotal; i++) {
		if (playerOneCreatures[i] == card) {
			playerOneCreatures[i] = nullptr;
			delete card;
			playerOneTotal--;
			return;
		}
	}
	for (int i = 0; i < playerTwoTotal; i++) {
		if (playerTwoCreatures[i] == card) {
			playerTwoCreatures[i] = nullptr;
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
		return false;
	}
	if (playerNum == 2) {
		if (playerOneTotal < maxCreatures) {
			playerTwoCreatures[playerTwoTotal++] = c;
			return true;
		}
		return false;
	}
	return false;
}

