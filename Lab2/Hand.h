#pragma once
#include <string>
#include "Deck.h"
#include "PlayingCard.h"

using namespace std;

enum HandRanks { NO_RANK = 0, ONE_PAIR, TWO_PAIRS, THREE_OF_A_KIND, STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH };

class Hand {
private:
	vector<PlayingCard> cards;
public:
	Hand();
	Hand(const Hand &);
	// No destructor; no dynamic memory allocation
	Hand & operator=(const Hand &);
	int size() const;
	bool operator==(const Hand &) const;
	bool operator<(const Hand &) const;
	string asString() const;
	int parseRank() const;
	vector<int> getComparisonVector(int) const;
	friend ostream & operator<<(ostream &, const Hand &);
	friend void operator<<(Hand &, Deck &);
	friend bool pokerRank(const Hand &, const Hand &);
};