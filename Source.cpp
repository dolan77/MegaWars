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

// method for when the War process starts
void War(map<int, Card>& CardToPlayer, Card& maxCard, vector<int>& playersIDWithMaxCard, vector<Player>::iterator& playerITR,
	vector<Player>& players, WarPile& warPile, LostAndFoundPile& lostAndFound) {
	cout << "cards in play: ";
	for (auto itr = CardToPlayer.begin(); itr != CardToPlayer.end(); itr++) {
		
		itr->second.showCard();

		if (itr == CardToPlayer.begin()) {
			maxCard = itr->second;
			continue;
		}

		if (maxCard < itr->second) {
			maxCard = itr->second;
		}

	}
	cout << endl;
	// iterates through the CardToPlayer map to check who's card contains the max value card. then add it to the playersIDWithMaxCard vector.
	for (auto& itr : CardToPlayer) {
		if (itr.second.getValue() == maxCard.getValue()) {
			playersIDWithMaxCard.push_back(itr.first);
		}
	}

	// if there is only 1 player with the maxCard.
	if (playersIDWithMaxCard.size() == 1) {

		// in this case, there is only 1 player with the max card
		// iterate through the players to see who's ID is in the playersIDWithMaxCard vector.
		for (playerITR = players.begin(); playerITR != players.end(); playerITR++) {
			// find the player with the same playerID
			if (playerITR->getPlayerID() == playersIDWithMaxCard[0]) {

				// give all the cards in war pile to the player that won
				// place the cards in the front of the player's pile vector since it starts from bottom of deck to top of deck.
				while (warPile.getPile().size() != 0) {

					// cheap way of doing it
					Card temp = warPile.remove();
					// playerITR->getPile().insert(playerITR->getPile().begin(), temp);
					playerITR->add(temp);

					// find a way to put the cards at the beginning of the vector or just pop then to the back of the vector
					// break;
				}
				// add cards from the lost pile into the player's hand as well

				while (lostAndFound.getSizeOfPile() != 0) {
					Card temp = lostAndFound.remove();
					// playerITR->getPile().insert(playerITR->getPile().begin(), temp);
					playerITR->add(temp);
				}
			}
		}
		// clear the map and the vector with the ID's that have the MaxCard to rerun the battle
		CardToPlayer.clear();
		playersIDWithMaxCard.clear();

	}

	// there are multiple players with the maxCard
	else {
		// iterate through each player that has the max card
		// NO I HAVE A MAP FOR A REASON
		for (auto IDitr = playersIDWithMaxCard.begin(); IDitr != playersIDWithMaxCard.end(); IDitr++) {

			for (playerITR = players.begin(); playerITR != players.end(); playerITR++) {

				// if we find the ID that matches with the player in the playerITR
				if (*IDitr == playerITR->getPlayerID()) {

					for (int i = 0; i < 3; i++) {
						// if the player has cards, remove 3 to fit the condition of war
						if (playerITR->getSizeOfPile() != 0) {
							warPile.add(playerITR->remove());
						}

					}

					// after pulling the 3 cards, if the player still has cards, remove 1 and change the CardToPlayer max, add that removed card to the warPile
					if (playerITR->getSizeOfPile() != 0) {
						CardToPlayer[playerITR->getPlayerID()] = playerITR->remove();
						warPile.add(CardToPlayer[playerITR->getPlayerID()]);
					}

				}

			}
		}
		// end of the for loops
		// once we get new cards, clear the playersIDWithMaxCard to rerun the warloop
	}

	playersIDWithMaxCard.clear();
}


// method that plays the Game of MegaWar
void Game(int &decks, int& numberOfPlayers) {
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
	
	int sizeOfMegaPile;
	vector<Player> players;
	LostAndFoundPile lostAndFound = LostAndFoundPile();
	WarPile warPile = WarPile();
	map<int, Card> CardToPlayer;


	

	// places the Player object into the players vector
	for (int i = 0; i < numberOfPlayers; i++) {
		players.push_back(Player());
	}

	// creates the megaDeck and shuffles it
	MegaDeck megaDeck(decks);
	megaDeck.shuffle();
	sizeOfMegaPile = megaDeck.getSizeOfPile();

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

	// this prints the stats
	/*for (playerITR = players.begin(); playerITR != players.end(); playerITR++) {
		playerITR->printStats();
	}*/


	// =================== THE ACTUAL GAME PART OF WAR =======================
	// game ends when every player but 1's pile == 0;
	// if we have p1 p2 p3 p4 and p3 lose, make sure to keep printing their stats but make sure to never remove cards from their pile
	// player wins the game one person has EVERY card in the deck.
	while(game){
		for (auto player : players) {
			if (player.getSizeOfPile() == sizeOfMegaPile) {
				cout << "=============== WE HAVE A WINNER ===============" << endl;
				cout << "player: " << player.getPlayerID() << " wins!" << endl;
				return;
			}
		}


		Card maxCard;
		vector<int> playersIDWithMaxCard;

		
		cout << "Battle: " << ++totalBattles << endl;
		for (playerITR = players.begin(); playerITR != players.end(); playerITR++) {

			// each key (player) can now be mapped to a value (Card)
			// sorts with player 1 being bottom of map, player n being highest, CARDS ARE NOT SORTED
			// as long as the player has cards, add them to the map to keep track of who's card beings to which player
			// add that card to the warPile so we can give the winner all the cards
			if (playerITR->getSizeOfPile() != 0) {
				CardToPlayer.insert(pair <int, Card>(playerITR->getPlayerID(), playerITR->remove()));
				warPile.add(CardToPlayer[playerITR->getPlayerID()]);
			}

			playerITR->printStats();

			// cout << "Player: " << playerITR->getPlayerID() << " " << playerITR->getSizeOfPile() << endl;
		}

		// after making all eligible players place a card, start the WAR process
		while (CardToPlayer.size() != 0) {
			// cout << "initiating war" << endl;
			// NEED TO TEST WHEN A PLAYER RUNS OUT OF CARDS!
			War(CardToPlayer, maxCard, playersIDWithMaxCard, playerITR, players, warPile, lostAndFound);
		}
		


		
	}
}



int main() {
	int decks;
	int numberOfPlayers;
	int input;

	// =============== INITIALIZING THE PLAYERS, DECKS, AND CARD DISTRIBUTION ================

	cout << "How many decks do you want? ";
	cin >> decks;
	cout << endl;

	cout << "How many players do you want? ";
	cin >> numberOfPlayers;
	cout << endl;

	Game(decks, numberOfPlayers);
	

	return 0;
}