/**
 * Defines the declared member functions in PlayingCard.h 
 */

#include "stdafx.h"
#include "PlayingCard.h"
#include <string>

using namespace std;

// Constructor for a playingCard with the given rank and suit descriptors.
PlayingCard::PlayingCard(string rankString, string suitString) {
	if (rankString == "2") {
		rank = Ranks::two;
	}
	else if (rankString == "3") {
		rank = Ranks::three;
	}
	else if (rankString == "4") {
		rank = Ranks::four;
	}
	else if (rankString == "5") {
		rank = Ranks::five;
	}
	else if (rankString == "6") {
		rank = Ranks::six;
	}
	else if (rankString == "7") {
		rank = Ranks::seven;
	}
	else if (rankString == "8") {
		rank = Ranks::eight;
	}
	else if (rankString == "9") {
		rank = Ranks::nine;
	}
	else if (rankString == "10") {
		rank = Ranks::ten;
	}
	else if (rankString == "J" || rankString == "j") {
		rank = Ranks::jack;
	}
	else if (rankString == "Q" || rankString == "q") {
		rank = Ranks::queen;
	}
	else if (rankString == "K" || rankString == "k") {
		rank = Ranks::king;
	}
	else if (rankString == "A" || rankString == "a") {
		rank = Ranks::ace;
	}

	if (suitString == "H" || suitString == "h") {
		suit = Suits::hearts;
	}
	else if (suitString == "D" || suitString == "d") {
		suit = Suits::diamonds;
	}
	else if (suitString == "S" || suitString == "s") {
		suit = Suits::spades;
	}
	else if (suitString == "C" || suitString == "c") {
		suit = Suits::clubs;
	}
}


// Returns a string descriptor of the provided playingCard.
string PlayingCard::toString() const {
	string output;
	if (rank == Ranks::two) {
		output += "2";
	}
	else if (rank == Ranks::three) {
		output += "3";
	}
	else if (rank == Ranks::four) {
		output += "4";
	}
	else if (rank == Ranks::five) {
		output += "5";
	}
	else if (rank == Ranks::six) {
		output += "6";
	}
	else if (rank == Ranks::seven) {
		output += "7";
	}
	else if (rank == Ranks::eight) {
		output += "8";
	}
	else if (rank == Ranks::nine) {
		output += "9";
	}
	else if (rank == Ranks::ten) {
		output += "10";
	}
	else if (rank == Ranks::jack) {
		output += "J";
	}
	else if (rank == Ranks::queen) {
		output += "Q";
	}
	else if (rank == Ranks::king) {
		output += "K";
	}
	else if (rank == Ranks::ace) {
		output += "A";
	}

	if (suit == Suits::hearts) {
		output += "H";
	}
	else if (suit == Suits::diamonds) {
		output += "D";
	}
	else if (suit == Suits::spades) {
		output += "S";
	}
	else if (suit == Suits::clubs) {
		output += "C";
	}

	return output;
}


bool PlayingCard::operator<(const PlayingCard & secondCard) const{
	return rank == secondCard.rank ? suit < secondCard.suit :
			rank < secondCard.rank;
}

bool PlayingCard::operator==(const PlayingCard & secondCard) const {
	return rank == secondCard.rank && suit == secondCard.suit;
}