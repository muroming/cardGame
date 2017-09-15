#include "stdafx.h"
#include "Card.h"
#include "Field.h"
#include "Player.h"
#include <iostream>

using namespace std;


void drawField(Field* f, Player* p1, Player* p2) {
	system("cls");
	int m = 10, n2 = f->getPlayerTwoTotal(), n1 = f->getPlayerOneTotal();
	p2->displayStatus();
	p2->displayHand();
	Card** c2 = f->getPlayerTwoCreatures(), **c1 = f->getPlayerOneCreatures();
	for (int i = 0; i < m; i++) {
		cout << "|  " << i + 1 << "  |";
		if (i != m - 1) {
			cout << " ";
		}
	}
	cout << endl;
	for (int i = 0; i < n2; i++) {
		cout << "  " << (c2[i]->getDmg()) << "/" << c2[i]->getHp() << "  ";
		if (i != n2 - 1) {
			cout << " ";
		}
	}
	cout << endl;
	for (int i = 0; i < m * 8; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < n1; i++) {
		cout << "  " << (c1[i]->getDmg()) << "/" << c1[i]->getHp() << "  ";
		if (i != n1 - 1) {
			cout << " ";
		}
	}
	cout << endl;
	p1->displayStatus();
	p1->displayHand();
}