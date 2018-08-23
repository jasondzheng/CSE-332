#include "stdafx.h"
#include "Deck.h"
#include <sstream>
#include <regex>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

Deck::Deck(string filename) {
	if (load(filename) != 0) {
		cards = vector<PlayingCard>();
	}
}

int Deck::load(string filename) {
	try {
		ifstream cardFile(filename);
		string cardDef;
		regex r("(10|[2-9]|[J,Q,K,A])([H,D,C,S])",
			regex_constants::ECMAScript | regex_constants::icase);
		while (cardFile >> cardDef) {
			smatch match;
			if (regex_match(cardDef, r) && regex_search(cardDef, match, r)) {
				string rank = match.str(1);
				string suit = match.str(2);
				cards.push_back(PlayingCard(rank, suit));
			}
		}
	}
	catch (...) {
		return 1;
	}
	return 0;
}

int randomNumber(int i) {
	srand(time(0));
	return std::rand() % i;
}

void Deck::shuffle() {
	random_shuffle(cards.begin(), cards.end(), randomNumber);
}

int Deck::size() const {
	return cards.size();
}

ostream & operator<< (ostream & os, const Deck & deck) {
	for (int i = 0; i < deck.cards.size(); ++i) {
		os << deck.cards[i].toString() << " ";
	}
	return os;
}