#include "MegaDeck.h"

using namespace std;

// overloaded constructor that creates x MegaDecks.
MegaDeck::MegaDeck(int number_of_decks) {
	// call deck multiple times to create a deck
	// createing a MegaDeck creates 1 deck already, so we subtract 1.
	for (int i = 0; i < number_of_decks - 1; i++) {
		createDeck();
	}
}