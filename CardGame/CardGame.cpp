// CardGame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Card.h"
#include "Player.h"
#include "Field.h"
#include "Game.h"
#include "Drawing.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//initialize 2 decks
	Card **deck1 = new Card*[10], **deck2 = new Card*[10];
	/*
		get decks from data base
	*/
	for (int i = 0; i < 10; i++) {
		deck1[i] = new Card(1, "ANUS", rand() % 4, rand() % 4);
		deck2[i] = new Card(1, "ANUS", rand() % 4, rand() % 4);
	}
	Game* game = new Game(deck1, deck2);
	game->startGame();
}

