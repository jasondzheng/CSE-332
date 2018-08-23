/**
 * Defines a PlayingCard struct and provides relavent functions:
 * a PlayingCard constructor given a rank string and suit string, a toString
 * function, and an overriden less-than operator.
 */

#pragma once
#ifndef PLAYING_CARD_H
#define PLAYING_CARD_H

#include <string>

using namespace std;

enum Suits { clubs = 0, diamonds, hearts, spades };
enum Ranks { two = 0, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };

struct PlayingCard {
	PlayingCard(string, string);
	string toString() const;
	bool operator<(const PlayingCard &) const;
	int suit;
	int rank;
};

#endif
