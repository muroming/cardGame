#pragma once
#include "Card.h"

class Field {
	Card** playerOneCreatures;
	Card** playerTwoCreatures;
	int playerOneTotal, playerTwoTotal;
public:
	Field();
	bool addCreature(Card* creature, int player12);
	bool creaturesFight(Card*attacking, Card* defending);
	void destroyCreature(Card* creature);
	Card** getPlayerOneCreatures();
	Card** getPlayerTwoCreatures();
	int getPlayerOneTotal();
	int getPlayerTwoTotal();
	Card* getCreature(int creature, int player12);
	void creaturesCheck();
	void activeAll(int player12);
};
