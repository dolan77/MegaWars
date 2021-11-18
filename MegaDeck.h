#ifndef MEGADECK_H
#define MEGADECK_H

#include "Deck.h"
#include "CardPile.h"
#include "Card.h"
#include <vector>
using namespace std;

class MegaDeck : public Deck {
public:
	MegaDeck(int);
};

#endif // !MEGADECK_H
