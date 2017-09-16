#include "stdafx.h"
#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


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
	int n;
	bool isOver;
	do {
		if (p1->active()) {
			f->activeAll(1);
		}
		else {
			f->activeAll(2);
		}
		//playing cards from hand
		do {
			drawField(f, p1, p2);
			std::cout << "(p)lay card/(c)ontinue: ";
			std::cin >> a;
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
		} while (a != 'c');
		f->creaturesCheck();
		//Fighting
		do{
			drawField(f, p1, p2);
			std::cout << "(a)ttack with creature/attack (p)layer/(c)ontinue: ";
			std::cin >> a;
			//atk creature
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
			//atk player
			if (a == 'p') {
				cout << "Attacking card num (-1 to exit): ";
				cin >> n;
				if (n == -1) {
					break;
				}
				
				if (p1->active()) {
					Card* c = f->getCreature(n, 1);
					if (c->active()) {
						p2->takeDmg(c->getDmg());
						c->setActive(false);
					}
					else {
						cout << "Chosen creature is not active\n";
						_sleep(1000);
					}
					if (p2->dead()) {
						break;
					}
				}
				else {
					Card* c = f->getCreature(n, 2);
					if (c->active()) {
						p1->takeDmg(c->getDmg());
						c->setActive(false);
					}
					else {
						cout << "Chosen creature is not active\n";
						_sleep(1000);
					}
					if (p1->dead()) {
						break;
					}
				}
			}
		} while (a != 'c');
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
				cout << "Not enougth mana\n";
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
					cout << "Not enough mana\n";
					return false;
				}
			}
		}
		return false;
	}
}
