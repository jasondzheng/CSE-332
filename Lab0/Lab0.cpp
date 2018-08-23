/**
 * Parses CDSs(card descriptor string) from the file at the provided filename 
 * and stores each valid CDS as a PlayingCard in a vector. Upon successful 
 * parsing, outputs each PlayingCard as a CDS. Prints out appropriate error
 * codes for each function.
 */

#include "stdafx.h"
#include "PlayingCard.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

#define NUM_ARGS 2

using namespace std;

enum ErrorCodes { INCORRECT_ARGUMENTS = 1, PARSE_FILE_ERROR, PRINT_CARDS_ERROR,
		FAILED_TO_TERMINATE };


// Prints the usage instructions. 
// Returns 1.
int printUsageMessage(char * name) {
	cout << name << ": Please run with the filename of the text file" << 
			" containing card descriptors: card_file.txt" << endl ;
	return ErrorCodes::INCORRECT_ARGUMENTS;
}


// Parses and stores playingCards from valid card descriptors. 
// Returns 0 upon success, 2 upon failure.
int parseCardsFromFile(vector<PlayingCard> & cardsVector, char * fileName) {
	try {
		ifstream cardFile(fileName);
		string cardDef;
		regex r("(10|[2-9]|[J,Q,K,A])([H,D,C,S])", 
				regex_constants::ECMAScript | regex_constants::icase);
		while (cardFile >> cardDef) {
			smatch match;
			if (regex_match(cardDef, r) && regex_search(cardDef, match, r)) {
				string rank = match.str(1);
				string suit = match.str(2);
				cardsVector.push_back(makePlayingCard(rank, suit));
			}
		}
	} catch (...) {
		return ErrorCodes::PARSE_FILE_ERROR;
	}
	return 0;
}


// Prints all PlayingCards in the provided cardsVector as card descriptors. 
// Returns 0 upon success, 3 upon failure.
int printCardsVector(const vector<PlayingCard> cardsVector) {
	try {
		for (int i = 0; i < cardsVector.size(); ++i) {
			cout << playingCardToString(cardsVector[i]) << " ";
		}
	} catch (...) {
		return ErrorCodes::PRINT_CARDS_ERROR;
	}
	return 0;
}


int main(int argc, char * argv[]) {
	if (argc != NUM_ARGS) {
		return printUsageMessage(argv[0]);
	}
	vector<PlayingCard> cardsVector;
	int value = parseCardsFromFile(cardsVector, argv[1]);
	return value == 0 ? printCardsVector(cardsVector) : value;
	return ErrorCodes::FAILED_TO_TERMINATE;
}

