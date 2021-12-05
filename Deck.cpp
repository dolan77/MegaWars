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
		for (int j = Card::rankAce - 1; j <= Card::rankKing - 1; j++) {
			add(Card(ranks[j], suits[i]));
		}
	}
}