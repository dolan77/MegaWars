#ifndef CARDPILE_H
#define CARDPILE_H

#include <iostream>
#include <algorithm>
#include "Card.h"
#include <vector>

using namespace std;

class CardPile {
protected: vector<Card> card_pile;
public:
	void add(Card);
	Card remove();
	vector<Card> getPile();
	void printPile();
	int getSizeOfPile();
	void shuffle();
};


#endif // !CARDPILE_H

