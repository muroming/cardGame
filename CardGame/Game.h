#pragma once

#include "stdafx.h"
#include "Card.h"
#include "Player.h"
#include "Field.h"
#include "Drawing.h"

class Game {
	Field *f;
	Player *p1, *p2;
	Card **deck1, **deck2;
public:
	Game(Card**, Card**);
	bool chooseAndPlayCard(int);
	void creaturesFight(Card*, Card*);
	void startGame();
};
