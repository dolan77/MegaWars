#ifndef PLAYER_H
#define PLAYER_H

#include "CardPile.h"
#include <iostream>
#include <vector>

using namespace std;
class Player : public CardPile {

private:
	int playerID;
	int battles;
	int wins;

	static int nextID;

public:
	
	Player();
	void printStats();
	double getFierceness();
	int getPlayerID();
	void incrementWin();
	void incrementBattles();
};

#endif // !PLAYER_H
