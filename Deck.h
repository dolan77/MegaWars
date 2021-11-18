#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "CardPile.h"
#include "Card.h"

using namespace std;

class Deck : public CardPile {
private:
	char suits[4] = { 'S', 'C', 'H', 'D' };
	char ranks[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

public:
	Deck();
	void createDeck();
};

#endif // !DECK_H
