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

	switch(rank){
	case 'A':
		return rankAce;
	case '2':
		return rankTwo;
	case '3':
		return rankThree;
	case '4':
		return rankFour;
	case '5':
		return rankFive;
	case '6':
		return rankSix;
	case '7':
		return rankSeven;
	case '8':
		return rankEight;
	case '9':
		return rankNine;
	case 'T':
		return rankTen;
	case 'J':
		return rankJack;
	case 'Q':
		return rankQueen;
	case 'K':
		return rankKing;

	}


	// return the distance from the beginning of the ranks array to where the element is + 1.
	// the + 1 is there since the array indexes from 0-12 when we want values from 1-13
	// return distance(ranks, find(begin(ranks), end(ranks), rank) + 1);
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
	int rank1 = 0;
	int rank2 = 0;

	switch (rank) {
	case 'A':
		rank1 = rankAce;
		break;
	case '2':
		rank1 = rankTwo;
		break;
	case '3':
		rank1 = rankThree;
		break;
	case '4':
		rank1 = rankFour;
		break;
	case '5':
		rank1 = rankFive;
		break;
	case '6':
		rank1 = rankSix;
		break;
	case '7':
		rank1 = rankSeven;
		break;
	case '8':
		rank1 = rankEight;
		break;
	case '9':
		rank1 = rankNine;
		break;
	case 'T':
		rank1 = rankTen;
		break;
	case 'J':
		rank1 = rankJack;
		break;
	case 'Q':
		rank1 = rankQueen;
		break;
	case 'K':
		rank1 = rankKing;
		break;
	}

	switch (otherCard.rank) {
	case 'A':
		rank2 = rankAce;
		break;
	case '2':
		rank2 = rankTwo;
		break;
	case '3':
		rank2 = rankThree;
		break;
	case '4':
		rank2 = rankFour;
		break;
	case '5':
		rank2 = rankFive;
		break;
	case '6':
		rank2 = rankSix;
		break;
	case '7':
		rank2 = rankSeven;
		break;
	case '8':
		rank2 = rankEight;
		break;
	case '9':
		rank2 = rankNine;
		break;
	case 'T':
		rank2 = rankTen;
		break;
	case 'J':
		rank2 = rankJack;
		break;
	case 'Q':
		rank2 = rankQueen;
		break;
	case 'K':
		rank2 = rankKing;
		break;
	}

	//cout << "current card: " << rank << suit << endl;
	//cout << "other card: " << otherCard.rank << otherCard.suit << endl;
	
	// if the distnace of the current card is not less than the distance of the other card, return false.
	// int rank1 = distance(ranks, find(begin(ranks), end(ranks), rank) + 1);
	// int rank2 = distance(ranks, find(begin(ranks), end(ranks), otherCard.rank) + 1);
	if ( !( rank1 < rank2) ) {
		return false;
	}

	return true;
}