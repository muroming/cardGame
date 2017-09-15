#pragma once

class Player {
	int hp, totalCards, mana, turn = 0, deckSize = 10;
	const int maxCards = 10;
	bool isDead, isActive;
	Card **hand;
	Card **deck;
public:
	Player(Card**);
	void takeDmg(int);
	bool dead();
	bool takeCard();
	bool active();
	void newTurn();
	void newGame();
	void displayHand();
	void endTurn();
	int getMana();
	void spendMana(int);
	Card* getCardFromHandByNum(int);
	void cardPlayed(int);
};
