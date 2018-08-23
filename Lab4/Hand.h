#pragma once
#ifndef HAND_H
#define HAND_H

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
	PlayingCard operator[](size_t);
	void removeCard(size_t);
	string asString() const;
	int parseRank() const;
	vector<int> getComparisonVector(int) const;
	static bool pokerRank(const Hand &, const Hand &);
	friend ostream & operator<<(ostream &, const Hand &);
	friend void operator<<(Hand &, Deck &);
	friend void operator<<(Deck &, Hand &);
	friend void dealFaceDownCard(Hand &, Deck &);
	void printCardsWithFaceDown();
};

#endif