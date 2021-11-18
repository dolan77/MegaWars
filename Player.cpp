#include "Player.h"
#include <iomanip>
using namespace std;

int Player::nextID = 0;

// default constructor
Player::Player() {
	battles = 0;
	wins = 0;
	// create unique player id's when creating multiple players
	playerID = ++nextID;
}



// method that calculates and return the fierceness of a player's hand / pile
double Player::getFierceness() {
	vector<Card>::iterator itr;
	double total_value = 0;

	// if the player has no cards in their card_pile, then their fierceness == 0;
	if (card_pile.size() == 0) {
		return total_value;
	}

	// iterate through the card_pile and add the values of the card into the total_value variable.
	for (itr = card_pile.begin(); itr != card_pile.end(); itr++) {
		total_value += (double) itr->getValue();
	}

	// return the average of total_value, rounded to two decimal places
	return ceil( ( ( total_value / card_pile.size() ) * 100.0 ) ) / 100.0;

}


// method that returns the player's ID
int Player::getPlayerID() {
	return playerID;
}


// method that prints prints playerID, their Fierceness, Cardsleft, battles partaken in, amount of wins
void Player::printStats() {
	cout << "Player " << playerID 
		<< " : Fierceness = " << getFierceness() 
		<< "\t" << "Cards = "  << card_pile.size() 
		<< "\t" << "Battles = " << battles 
		<< "\t" << "Won = " << wins << endl;
}