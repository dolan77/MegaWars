#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "CardPile.h"
#include "Card.h"

using namespace std;

class Deck : public CardPile {

public:
	Deck();
	void createDeck();
};

#endif // !DECK_H
