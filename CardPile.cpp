#include "CardPile.h"

using namespace std;

// adds a card to the pile
void CardPile::add(Card c) {
	
	card_pile.push_back(c);
}


// removes a card from the pile
Card CardPile::remove() {
	// make the temp card the last card in the deck
	Card temp = card_pile[card_pile.size() - 1];
	card_pile.pop_back();

	return temp;
}


// returns the card_pile vector
vector<Card> CardPile::getPile() {
	return card_pile;
}

// method that will print the pile of cards in card_pile
void CardPile::printPile() {
	// iterate through card_pile and print out the cards.
	vector<Card>::iterator itr;
	for (itr = card_pile.begin(); itr != card_pile.end(); itr++) {
		itr->showCard();
	}
}


// gets the size of the card pile
int CardPile::getSizeOfPile() {
	return card_pile.size();
}

void CardPile::shuffle() {
	// randomly shuffle the pile of cards
	std::random_shuffle(card_pile.begin(), card_pile.end());
}