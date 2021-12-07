#include "Deck.h"
#include <vector>
using namespace std;

Deck::Deck() {
	// creates one deck
	createDeck();
	
}

void Deck::createDeck() {
	// i = suit, j = rank
	// iterate using enum values for suit and rank
	for (int i = Card::suitSpade; i <= Card::suitDiamond; i++) {
		for (int j = Card::rankAce; j <= Card::rankKing; j++) {
			add(Card(Card::ranks(j), Card::suits(i)));
		}
	}
}