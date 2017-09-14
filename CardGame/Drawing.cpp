#include "stdafx.h"
#include "Card.h"
#include <iostream>

using namespace std;


void drawField(Card** p1, Card** p2, int n1, int n2) {
	system("cls");
	int m = 10;
	for (int i = 0; i < m; i++) {
		cout << "|  " << i + 1 << "  |";
		if (i != m - 1) {
			cout << " ";
		}
	}
	cout << endl;
	for (int i = 0; i < n2; i++) {
		cout << " " << (p2[i]->getDmg()) << "/" << p2[i]->getHp() << " ";
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
		cout << " " << (p1[i]->getDmg()) << "/" << p1[i]->getHp() << " ";
		if (i != n1 - 1) {
			cout << " ";
		}
	}
}