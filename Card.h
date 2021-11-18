#ifndef CARD_H
#define CARD_H

#include <iostream>
class Card {
private:
	char rank;
	char suit;
	char suits[4] = { 'S', 'C', 'H', 'D' };
	char ranks[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

public:
	Card();
	Card(char, char);
	void setCard(char, char);
	int getValue();
	void showCard();
	bool operator<( const Card&) const;
};





#endif // !CARD_H

