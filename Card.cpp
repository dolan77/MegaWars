#include "Card.h"
#include <string>

using namespace std;

Card::Card() {
	rank = rankEmpty;
	suit = suitEmpty;
}

Card::Card(ranks r, suits s) {
	this->rank = ranks(r);
	this->suit = suits(s);
}

void Card::setCard(ranks r, suits s) {
	rank = ranks(r);
	suit = suits(s);
}

int Card::getValue() {

	// depending on the current card rank, return values from the enum list
	switch(rank){
	case rankAce:
		return int(rankAce);
	case rankTwo:
		return int(rankTwo);
	case rankThree:
		return int(rankThree);
	case rankFour:
		return int(rankFour);
	case rankFive:
		return int(rankFive);
	case rankSix:
		return int(rankSix);
	case rankSeven:
		return int(rankSeven);
	case rankEight:
		return int(rankEight);
	case rankNine:
		return int(rankNine);
	case rankTen:
		return int(rankTen);
	case rankJack:
		return int(rankJack);
	case rankQueen:
		return int(rankQueen);
	case rankKing:
		return int(rankKing);
	case rankEmpty:
		return int(rankEmpty);
	}


	// return the distance from the beginning of the ranks array to where the element is + 1.
	// the + 1 is there since the array indexes from 0-12 when we want values from 1-13
	// return distance(ranks, find(begin(ranks), end(ranks), rank) + 1);
}

void Card::showCard() {
	string output;

	// compensated by adding int values to get the ascii value of the characters to print to the console.
	switch (rank) {
	case rankAce:
		output += (rankAce) + 64;
		break;
	case rankTwo:
		output += (rankTwo) + 48;
		break;
	case rankThree:
		output += (rankThree) + 48;
		break;
	case rankFour:
		output += (rankFour) + 48;
		break;
	case rankFive:
		output += (rankFive) + 48;
		break;
	case rankSix:
		output += (rankSix) + 48;
		break;
	case rankSeven:
		output += (rankSeven) + 48;
		break;
	case rankEight:
		output += (rankEight) + 48;
		break;
	case rankNine:
		output += (rankNine) + 48;
		break;
	case rankTen:
		output += (rankTen) + 39;
		output += (rankTen) + 38;
		break;
	case rankJack:
		output += (rankJack) + 63;
		break;
	case rankQueen:
		output += (rankQueen) + 69;
		break;
	case rankKing:
		output += (rankKing) + 62;
		break;
	case rankEmpty:
		output += 'x';
		break;
	}

	switch (suit) {
	case suitDiamond:
		output += 'D';
		break;
	case suitClover:
		output += 'C';
		break;
	case suitHeart:
		output += 'H';
		break;
	case suitSpade:
		output += 'S';
		break;
	case suitEmpty:
		output += 'x';
		break;
	}

	cout << output << " ";


	/*if (rank == 'T') {
		cout << "10" << suit << " ";
	}
	else {
		cout << rank << suit << " ";
	}*/
}

bool Card::operator<( const Card& otherCard) const {
	int rank1 = 0;
	int rank2 = 0;

	// get the current value of the rank using the enum list.
	switch (rank) {
	case rankAce:
		rank1 = rankAce;
		break;
	case rankTwo:
		rank1 = rankTwo;
		break;
	case rankThree:
		rank1 = rankThree;
		break;
	case rankFour:
		rank1 = rankFour;
		break;
	case rankFive:
		rank1 = rankFive;
		break;
	case rankSix:
		rank1 = rankSix;
		break;
	case rankSeven:
		rank1 = rankSeven;
		break;
	case rankEight:
		rank1 = rankEight;
		break;
	case rankNine:
		rank1 = rankNine;
		break;
	case rankTen:
		rank1 = rankTen;
		break;
	case rankJack:
		rank1 = rankJack;
		break;
	case rankQueen:
		rank1 = rankQueen;
		break;
	case rankKing:
		rank1 = rankKing;
		break;
	}

	// get the otherCard's rank using the enum list
	switch (otherCard.rank) {
	case rankAce:
		rank2 = rankAce;
		break;
	case rankTwo:
		rank2 = rankTwo;
		break;
	case rankThree:
		rank2 = rankThree;
		break;
	case rankFour:
		rank2 = rankFour;
		break;
	case rankFive:
		rank2 = rankFive;
		break;
	case rankSix:
		rank2 = rankSix;
		break;
	case rankSeven:
		rank2 = rankSeven;
		break;
	case rankEight:
		rank2 = rankEight;
		break;
	case rankNine:
		rank2 = rankNine;
		break;
	case rankTen:
		rank2 = rankTen;
		break;
	case rankJack:
		rank2 = rankJack;
		break;
	case rankQueen:
		rank2 = rankQueen;
		break;
	case rankKing:
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