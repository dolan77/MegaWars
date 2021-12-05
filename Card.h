#ifndef CARD_H
#define CARD_H

#include <iostream>
class Card {
private:
	char rank;
	char suit;
	// char suits[4] = { 'S', 'C', 'H', 'D' };
	// char ranks[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

public:
	enum ranks {
		rankAce = 1, rankTwo, rankThree, rankFour, rankFive, rankSix, rankSeven, rankEight, rankNine,
		rankTen, rankJack, rankQueen, rankKing
	};
	enum suits {
		suitSpade, suitClover, suitHeart, suitDiamond
	};

	Card();
	Card(char, char);
	void setCard(char, char);
	int getValue();
	void showCard();
	bool operator<( const Card&) const;
};





#endif // !CARD_H

