#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "PlayingCard.h"

using namespace std;

//forward declaration of Hand
class Hand;

class Deck {
private:
	vector<PlayingCard> cards;
public:
	Deck(string filename);
	// Desctructor not neccessary; no dynamic memory allocation
	int load(string filename);
	void shuffle();
	int size() const;
	friend ostream & operator<<(ostream & os, const Deck & deck);
	friend void operator<<(Hand &, Deck &);
};
