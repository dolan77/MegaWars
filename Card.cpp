#include "Card.h"


using namespace std;

Card::Card() {
	rank = 'x';
	suit = 'x';
}

Card::Card(char rank, char suit) {
	this->rank = rank;
	this->suit = suit;
}

void Card::setCard(char rank, char suit) {
	this->rank = rank;
	this->suit = suit;
}

int Card::getValue() {
	
	// return the distance from the beginning of the ranks array to where the element is + 1.
	// the + 1 is there since the array indexes from 0-12 when we want values from 1-13
	 return distance(ranks, find(begin(ranks), end(ranks), rank) + 1);
}

void Card::showCard() {
	if (rank == 'T') {
		cout << "10" << suit << " ";
	}
	else {
		cout << rank << suit << " ";
	}
}

bool Card::operator<( const Card& otherCard) const {
	// if the distnace of the current card is not less than the distance of the other card, return false.
	int rank1 = distance(ranks, find(begin(ranks), end(ranks), rank) + 1);
	int rank2 = distance(ranks, find(begin(ranks), end(ranks), otherCard.rank) + 1);
	if ( !( rank1 < rank2) ) {
		return false;
	}

	return true;
}