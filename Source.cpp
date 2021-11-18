#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include "MegaDeck.h"
#include "Deck.h"
#include "CardPile.h"
#include "Card.h"
#include "Player.h"
#include "LostAndFoundPile.h"
#include "WarPile.h"
using namespace std;


int main() {
	bool game = true;
	int totalBattles = 0;

	//MegaDeck mega_deck = MegaDeck(2);
	//cout << mega_deck.getSizeOfPile() << endl;
	//mega_deck.printPile();
	//cout << endl;

	// creates a personal cardpile for the player
	//cout << "PLAYER" << endl;
	//Player player1 = Player();
	//player1.add(Card('K', 'S'));
	//player1.printStats();
	

	vector<Player>::iterator playerITR;
	int decks;
	int numberOfPlayers;
	vector<Player> players;
	LostAndFoundPile lostAndFound = LostAndFoundPile();
	WarPile warPile = WarPile();
	map<int, Card> CardToPlayer;


	// =============== INITIALIZING THE PLAYERS, DECKS, AND CARD DISTRIBUTION ================

	cout << "How many decks do you want? ";
	cin >> decks;
	cout << endl;

	cout << "How many players do you want? ";
	cin >> numberOfPlayers;
	cout << endl;

	// places the Player object into the players vector
	for (int i = 0; i < numberOfPlayers; i++) {
		players.push_back(Player());
	}

	// creates the megaDeck and shuffles it
	MegaDeck megaDeck(decks);
	megaDeck.shuffle();

	// if the cards cannot be evenly divided to the players, remove cards until it can and add them to the lostAndFound pile.
	while (megaDeck.getSizeOfPile() % numberOfPlayers != 0) {
		lostAndFound.add(megaDeck.remove());
	}

	// after removing the extra cards, keep giving players card until the deck runs out of cards
	while (megaDeck.getSizeOfPile() != 0) {
		// deck.size % num of players will give us values of 0 - (MAXPLAYERS - 1), or the indexes of the players vector
		// add the removed card to the player's pile
		players[megaDeck.getSizeOfPile() % numberOfPlayers].add(megaDeck.remove());
	}

	for (playerITR = players.begin(); playerITR != players.end(); playerITR++) {
		playerITR->printStats();
	}

	// =================== THE ACTUAL GAME PART OF WAR =======================
	// game when every player but 1's pile == 0;
	// if we have p1 p2 p3 p4 and p3 lose, make sure to keep printing their stats but make sure to never remove cards from their pile
	while (game) {
		

		for (int i = 0; i < players.size(); i++) {
			// each key (player) can now be mapped to a value (Card)
			// sorts with player 1 being bottom of map, player n being highest, CARDS ARE NOT SORTED
			// as long as the player has cards, add them to the map to keep track of who's card beings to which player
			// add that card to the warPile so we can give the winner all the cards
			if (players[i].getSizeOfPile() != 0) {
				CardToPlayer.insert(pair <int, Card>(players[i].getPlayerID(), players[i].remove()));
				warPile.add(CardToPlayer[i]);
			}
			
		}


	}



	return 0;
}