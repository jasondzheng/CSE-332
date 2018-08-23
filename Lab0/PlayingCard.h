/**
 * Defines a PlayingCard struct and provides relavent functions:
 * a PlayingCard constructor given a CDS(card descriptor string) and 
 * PlayingCard to CDS converter.
 */

#pragma once
#ifndef PLAYING_CARD_H
#define PLAYING_CARD_H

#include <string>

using namespace std;

enum Suits { clubs = 0, diamonds, hearts, spades };
enum Ranks { two = 0, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };

struct PlayingCard {
	int suit;
	int rank;
};

// Returns a playingCard with the given rank and suit descriptors.
PlayingCard makePlayingCard(string rank, string suit) {
	PlayingCard card;
	if (rank == "2") {
		card.rank = Ranks::two;
	} else if (rank == "3") {
		card.rank = Ranks::three;
	} else if (rank == "4") {
		card.rank = Ranks::four;
	} else if (rank == "5") {
		card.rank = Ranks::five;
	} else if (rank == "6") {
		card.rank = Ranks::six;
	} else if (rank == "7") {
		card.rank = Ranks::seven;
	} else if (rank == "8") {
		card.rank = Ranks::eight;
	} else if (rank == "9") {
		card.rank = Ranks::nine;
	} else if (rank == "10") {
		card.rank = Ranks::ten;
	} else if (rank == "J" || rank == "j") {
		card.rank = Ranks::jack;
	} else if (rank == "Q" || rank == "q") {
		card.rank = Ranks::queen;
	} else if (rank == "K" || rank == "k") {
		card.rank = Ranks::king;
	} else if (rank == "A" || rank == "a") {
		card.rank = Ranks::ace;
	}

	if (suit == "H" || suit == "h") {
		card.suit = Suits::hearts;
	} else if (suit == "D" || suit == "d") {
		card.suit = Suits::diamonds;
	} else if (suit == "S" || suit == "s") {
		card.suit = Suits::spades;
	} else if (suit == "C" || suit == "c") {
		card.suit = Suits::clubs;
	}
	
	return card;
}

// Returns a string descriptor of the provided playingCard.
string playingCardToString(PlayingCard card) {
	string output;
	if (card.rank == Ranks::two) {
		output += "2";
	} else if (card.rank == Ranks::three) {
		output += "3";
	} else if (card.rank == Ranks::four) {
		output += "4";
	} else if (card.rank == Ranks::five) {
		output += "5";
	} else if (card.rank == Ranks::six) {
		output += "6";
	} else if (card.rank == Ranks::seven) {
		output += "7";
	} else if (card.rank == Ranks::eight) {
		output += "8";
	} else if (card.rank == Ranks::nine) {
		output += "9";
	} else if (card.rank == Ranks::ten) {
		output += "10";
	} else if (card.rank == Ranks::jack) {
		output += "J";
	} else if (card.rank == Ranks::queen) {
		output += "Q";
	} else if (card.rank == Ranks::king) {
		output += "K";
	} else if (card.rank == Ranks::ace) {
		output += "A";
	}

	if (card.suit == Suits::hearts) {
		output += "H";
	} else if (card.suit == Suits::diamonds) {
		output += "D";
	} else if (card.suit == Suits::spades) {
		output += "S";
	} else if (card.suit == Suits::clubs) {
		output += "C";
	}

	return output;
}

#endif
