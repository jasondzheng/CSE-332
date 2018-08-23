#pragma once
#ifndef PLAYER_H
#define PLAYER_h

#include <string>
#include "PlayingCard.h"
#include "Hand.h"
#include "Deck.h"


using namespace std;

struct Player {
	string name;
	Hand hand;
	unsigned int handsWon;
	unsigned int handsLost;
	Player(string);
};

ostream & operator<<(const ostream &, const Player &);

#endif