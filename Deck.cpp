#include "Deck.h"
#include <vector>
using namespace std;

Deck::Deck() {
	// creates one deck
	createDeck();
	
}

void Deck::createDeck() {
	// i = suit, j = rank
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			add(Card(ranks[j], suits[i]));
		}
	}
}