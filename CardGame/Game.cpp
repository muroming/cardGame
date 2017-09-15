#include "stdafx.h"
#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

void creaturesFight(Card* attacking, Card* defending) {

}

void Game::startGame() {
	srand(time(NULL));
	p1->newGame();
	p2->newGame();
	if (rand() % 2 == 0) {
		p1->newTurn();
	}
	else {
		p2->newTurn();
	}
	char a;
	do {
		drawField(f, p1, p2);
		std::cout << "(p)lay card/(c)ontinue: ";
		std::cin >> a;
		int n;
		bool isOver;
		if (a == 'p') {
			isOver = false;
			do {
				std::cout << "Card num (-1 to exit): ";
				std::cin >> n;
				if (n == -1) {
					break;
				}
				isOver = chooseAndPlayCard(n);
			} while (!isOver);
		}
		drawField(f, p1, p2);
		std::cout << "(a)ttack with creature/(c)ontinue: ";
		std::cin >> a;
		if (a == 'a') {
			isOver = false;
			do {
				cout << "Attacking card num (-1 to exit): ";
				cin >> n;
				if (n == -1) {
					break;
				}
				int p;
				if (p1->active()) {
					p = 1;
				}
				else {
					p = 2;
				}
				Card* atk = f->getCreature(n, p);
				cout << "Creature to attack num (-1 to rechoose): ";
				cin >> n;
				if (n == -1) {
					continue;
				}
				if (p1->active()) {
					p = 2;
				}
				else {
					p = 1;
				}
				isOver = f->creaturesFight(atk, f->getCreature(n, p));
			} while (!isOver);
		}
		f->creaturesCheck();
		if (p1->active()) {
			p1->endTurn();
			p2->newTurn();
		}
		else {
			p2->endTurn();
			p1->newTurn();
		}
	} while (!p1->dead() || !p2->dead());
}


Game::Game(Card **deck1, Card **deck2) {
	f = new Field();
	p1 = new Player(deck1);
	p2 = new Player(deck2);
}

bool Game::chooseAndPlayCard(int n) {
	Card *card;
	if (p1->active()) {
		card = p1->getCardFromHandByNum(n);
		if (card->creature()) {
			if (p1->getMana() >= card->getManacost()) {
				p1->spendMana(card->getManacost());
				f->addCreature(card, 1);
				card = nullptr;
				p1->cardPlayed(n);
				return true;
			}
			else {
				//warn
				return false;
			}
		}
	}
	else {
		card = p2->getCardFromHandByNum(n);
		if (p2->active()) {
			if (card->creature()) {
				if (p2->getMana() >= card->getManacost()) {
					p2->spendMana(card->getManacost());
					f->addCreature(card, 2);
					card = nullptr;
					p2->cardPlayed(n);
					return true;
				}
				else {
					//warn
					return false;
				}
			}
		}
		return false;
	}
}
