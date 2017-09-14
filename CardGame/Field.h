#pragma once
#include "Card.h"

class Field {
	Card** playerOneCreatures;
	Card** playerTwoCreatures;
	int playerOneTotal, playerTwoTotal;
public:
	Field();
	bool addCreature(Card*, int);
	void creaturesFight(Card*, Card*);
	void destroyCreature(Card*);
	Card** getPlayerOneCreatures();
	Card** getPlayerTwoCreatures();
	int getPlayerOneTotal();
	int getPlayerTwoTotal();
};
