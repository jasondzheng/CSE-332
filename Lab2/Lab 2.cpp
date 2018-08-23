// Lab 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Hand.h"
#include "Deck.h"
#include <string>
#include <iostream>
#include <algorithm>

#define NUM_HANDS 9
#define CARDS_PER_HAND 5

using namespace std;

enum ErrorCodes { NO_ARGUMENTS = 1, TOO_MANY_ARGUMENTS, NO_FILENAME, PARSE_ERROR };

bool pokerRank(const Hand & hand1, const Hand & hand2) {
	int hand1Rank = hand1.parseRank();
	int hand2Rank = hand2.parseRank();
	if (hand1Rank != hand2Rank) {
		return hand1Rank > hand2Rank;
	} else {
		vector<int> hand1ComparisonVector = hand1.getComparisonVector(hand1Rank);
		vector<int> hand2ComparisonVector = hand2.getComparisonVector(hand2Rank);
		if (hand1ComparisonVector.size() != hand2ComparisonVector.size()) {
			return hand1ComparisonVector.size() > hand2ComparisonVector.size();
		}
		for (int i = 0; i < hand1ComparisonVector.size(); ++i) {
			if (hand1ComparisonVector[i] != hand2ComparisonVector[i]) {
				return hand1ComparisonVector[i] > hand2ComparisonVector[i];
			}
		}
	}
	return false;
}

int main(int argc, char * argv[]) {
	string filename;
	bool isShuffled = false;
	
	if (argc == 1) {
		cout << argv[0] << ": Please run program with cards filename and optional -shuffle option" << endl;
		return ErrorCodes::NO_ARGUMENTS;
	}
	if (argc > 3) {
		cout << argv[0] << ": Too many arguments" << endl;
		return ErrorCodes::TOO_MANY_ARGUMENTS;
	}
	if (argc == 2 && argv[1] == "-shuffle") {
		cout << argv[0] << ": Please provide cards filename" << endl;
		return ErrorCodes::NO_FILENAME;
	}
	if (argc == 3) {
		if (!strcmp(argv[1], "-shuffle")/*returns 0 if true*/) {
			filename = argv[2];
			isShuffled = true;
		} else if (!strcmp(argv[2], "-shuffle")/*returns 0 if true*/) {
			filename = argv[1];
			isShuffled = true;
		} else {
			cout << argv[0] << ": Please provide cards filename and optional -shuffle option" << endl;
			return ErrorCodes::NO_FILENAME;
		}
	} else {
		filename = argv[1];
	}

	try {
		Deck deck(filename);

		if (isShuffled) {
			cout << "SHUFFLED" << endl;
			deck.shuffle();
		}

		vector<Hand> hands;

		for (int i = 0; i < NUM_HANDS; ++i) {
			Hand hand;
			hands.push_back(hand);
		}

		for (int i = 0; i < CARDS_PER_HAND; ++i) {
			for (int j = 0; j < NUM_HANDS; ++j) {
				hands[j] << deck;
			}
		}

		cout << "Remaining Cards in Deck:" << endl;
		cout << deck << endl;

		cout << "Hands:" << endl;
		for (int i = 0; i < NUM_HANDS; ++i) {
			cout << hands[i] << endl;
		}

		cout << "Sorted Hands by Hand:" << endl;
		sort(hands.begin(), hands.end());
		for (int i = 0; i < NUM_HANDS; ++i) {
			cout << hands[i] << endl;
		}

		cout << "Sorted Hands by PokerRank:" << endl;
		sort(hands.begin(), hands.end(), pokerRank);
		for (int i = 0; i < NUM_HANDS; ++i) {
			cout << hands[i] << endl;
		}

		return 0;
	} catch (...) {
		return ErrorCodes::PARSE_ERROR;
	}
}

