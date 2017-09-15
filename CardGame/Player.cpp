#include "stdafx.h"
#include "Card.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

using namespace std;

Card* Player::getCardFromHandByNum(int num) {
	return hand[num - 1];
}

int Player::getMana() {
	return mana;
}

void Player::spendMana(int m) {
	mana -= m;
}

bool Player::active() {
	return isActive;
}

void Player::endTurn() {
	isActive = false;
}

void Player::displayHand() {
	cout << endl;
	for (int i = 0; i < totalCards; i++) {
		cout << hand[i]->getName() << " (" << hand[i]->getManacost() << ") ";
		if (hand[i]->creature()) {
			cout << "[" << hand[i]->getDmg() << "/" << hand[i]->getHp() << "]";
		}
		cout << endl;
	}
	cout << endl;
}

void Player::cardPlayed(int n) {
	for (int i = n - 1; i < totalCards-1; i++) {
		hand[i] = hand[i + 1];
	}
	hand[totalCards - 1] = nullptr;
	totalCards--;
}

void Player::newGame() {
	turn++;
	takeCard();
	turn++;
	takeCard();
	turn++;
	takeCard();
	turn++;
	takeCard();
	deck = (deck + turn - 1);
	turn = 0;
}

void Player::newTurn() {
	mana++;
	turn++;
	takeCard();
	mana = turn;
	isActive = true;
}

Player::Player(Card** d):hp(30), mana(0), isDead(0), totalCards(0), isActive(0) {
	srand(time(NULL));
	hand = new Card*[maxCards];
	deck = new Card*[deckSize];

	for (int i = 0; i < deckSize; i++) {//copy deck
		*(deck + i) = *(d + i);
	}

	for (int i = 0; i < 300; i++) {//shaffle deck
		int x1 = rand() % deckSize, x2;
		do {
			x2 = rand() % deckSize;
		}while(x1 == x2);
		Card* temp = *(deck + x1);
		*(deck + x1) = *(deck + x2);
		*(deck + x2) = temp;
	}
}

void Player::takeDmg(int dmg) {
	if (hp >= dmg) {
		hp -= dmg;
	}
	else {
		hp = 0;
		isDead = true;
	}
}

bool Player::dead() {
	return isDead;
}

bool Player::takeCard() {
	if (totalCards < maxCards) {
		*(hand + totalCards) = *(deck + turn - 1);
		totalCards++;
		return true;
	}
	else {
		return false;
	}
}