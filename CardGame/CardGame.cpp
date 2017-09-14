// CardGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Card.h"
#include "Player.h"
#include "Field.h"
#include "Drawing.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void chooseAndPlayCard(Card* card, Field* f, Player* p1, Player* p2) { 
	if (p1->active()) {
		if (card->creature) {
			f->addCreature(card, 1);
		}
	}
	else {
		if (p2->active()) {
			if (card->creature) {
				f->addCreature(card, 2);
			}
		}
	}
}

void creaturesFight(Card* attacking, Card* defending) {

}


int main()
{
	srand(time(NULL));
	Field *f = new Field();//create new field
	Card **deck1 = new Card*[10], **deck2 = new Card*[10];//initialize 2 decks
	/*
		get decks from data base
	*/
	for (int i = 0; i < 10; i++) {
		Card* c = new Card(i, string("Name: " + i), i, i);
		deck1[i] = c;
	}
	//init players w/ decks
	Player *p1 = new Player(deck1), *p2 = new Player(deck2);
	//start the game by making players draw 4 cards
	p1->newGame();
	p2->newGame();
	/*Randomly choose who goes first
	if (rand() % 1 == 0) {
		p1->newTurn();
	}
	else {
		p2->newTurn();
	}*/
	p1->newTurn();
	do {
		drawField(f->getPlayerOneCreatures(), f->getPlayerTwoCreatures(), f->getPlayerOneTotal(), f->getPlayerTwoTotal());
		p1->displayHand();
		system("pause");
	} while (!p1->dead() || !p2->dead());
}

