#ifndef CARD_H
#define CARD_H

#include <iostream>
class Card {
public:

	enum ranks {
		rankEmpty, rankAce, rankTwo, rankThree, rankFour, rankFive, rankSix, rankSeven, rankEight, rankNine,
		rankTen, rankJack, rankQueen, rankKing
	};
	enum suits {
		suitEmpty, suitSpade, suitClover, suitHeart, suitDiamond
	};

	Card();
	Card(ranks, suits);
	void setCard(ranks, suits);
	int getValue();
	void showCard();
	bool operator<(const Card&) const;

private:

	ranks rank;
	suits suit;

	// char suits[4] = { 'S', 'C', 'H', 'D' };
	// char ranks[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };


};





#endif // !CARD_H

