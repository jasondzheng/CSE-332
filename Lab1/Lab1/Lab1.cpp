/**
* Parses 5-card lines of CDSs(card descriptor string) from the file at the 
* provided filename and stores each valid CDS as a PlayingCard in a vector. 
* Upon successful parsing, outputs the type of each hand and each PlayingCard 
* as a CDS. Prints out appropriate error codes for each function.
*/

#include "stdafx.h"
#include "PlayingCard.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>
#include <vector>

#define NUM_ARGS 2

#define USAGE_MESSAGE "Please run with the card descriptor filename"

using namespace std;

enum ErrorCodes {
	INCORRECT_ARGUMENTS = 1, PARSE_FILE_ERROR, PRINT_CARDS_ERROR, 
	PARSE_AND_PRINT_HANDS_ERROR, FAILED_TO_TERMINATE
};


// Prints the usage instructions. 
// Returns 1.
int printUsageMessage(char * name, char * message) {
	cout << name << ": " << message << endl;
	return ErrorCodes::INCORRECT_ARGUMENTS;
}


// Parses and stores playingCards from valid card descriptors. 
// Returns 0 upon success, 2 upon failure.
int parseCardsFromFile(vector<PlayingCard> & cardsVector, char * fileName) {
	try {
		ifstream cardFile(fileName);
		string line;
		regex r1("\/\/.*");
		int lineNum = 0;
		while (getline(cardFile, line)) {
			// Take out comments
			line = regex_replace(line, r1, "");
			// Prepare line to be parsed
			istringstream lineStream(line);
			string cardDef;
			vector<PlayingCard> temp;
			regex r2("(10|[2-9]|[J,Q,K,A])([H,D,C,S])",
				regex_constants::ECMAScript | regex_constants::icase);
			while (lineStream >> cardDef) {
				smatch match;
				if (regex_match(cardDef, r2) && regex_search(cardDef, match, r2)) {
					string rank = match.str(1);
					string suit = match.str(2);
					temp.push_back(PlayingCard(rank, suit));
				}
			}
			if (temp.size() == 5) {
				sort(temp.begin(), temp.end());
				cardsVector.insert(cardsVector.end(), temp.begin(), temp.end());
			} else {
				// Print warning message
				cout << "Warning: line " << lineNum << 
						" has an invalid number of card descriptor strings" << 
						endl;
			}
			++lineNum;
		}
	}
	catch (...) {
		return ErrorCodes::PARSE_FILE_ERROR;
	}
	return 0;
}


// Parses a vector of valid hands of 5 Playing Cards. Prints out the type of 
// hand.
// Returns 4 upon failure.
int parseAndPrintHands(const vector<PlayingCard> & cardsVector) {
	try {
		for (int i = 0; i < cardsVector.size(); i += 5) {
			bool sameSuit = true;
			bool consecutive = true;
			for (int j = i; j < i + 4; ++j) {
				if (cardsVector[j].rank != cardsVector[j + 1].rank - 1) {
					consecutive = false;
				}
				if (cardsVector[j].suit != cardsVector[j + 1].suit) {
					sameSuit = false;
				}
			}
			if (sameSuit && consecutive) {
				cout << "straight flush" << endl;
				continue;
			}
			else if (sameSuit && !consecutive) {
				cout << "flush" << endl;
				continue;
			}
			else if (!sameSuit && consecutive) {
				cout << "straight" << endl;
				continue;
			}

			vector<int> occurrences;
			int sum = 1;
			int currRank = NULL;
			for (int j = i; j < i + 5; ++j) {
				if (currRank == cardsVector[j].rank) {
					++sum;
				}
				else if (j == i) {
					currRank = cardsVector[j].rank;
				}
				else {
					occurrences.push_back(sum);
					currRank = cardsVector[j].rank;
					sum = 1;
				}
			}
			occurrences.push_back(sum);

			if (occurrences.size() == 2) {
				if (occurrences[0] == 1 || occurrences[0] == 4) {
					cout << "four of a kind" << endl;
					continue;
				}
				else {
					cout << "full house" << endl;
					continue;
				}
			}

			if (occurrences.size() == 3) {
				if (occurrences[0] == 3 || occurrences[1] == 3 || occurrences[2] == 3) {
					cout << "three of a kind" << endl;
					continue;
				}
				else {
					cout << "two pairs" << endl;
					continue;
				}
			}

			if (occurrences.size() == 4) {
				cout << "one pair" << endl;
				continue;
			}

			cout << "no rank" << endl;
		}
	} catch (...) {
		cout << ErrorCodes::PARSE_AND_PRINT_HANDS_ERROR << endl;
	}
	return 0;
}


// Prints all PlayingCards in the provided cardsVector as card descriptors. 
// Returns 0 upon success, 3 upon failure.
int printCardsVector(const vector<PlayingCard> cardsVector) {
	try {
		for (int i = 0; i < cardsVector.size(); ++i) {
			cout << cardsVector[i].toString() << " ";
		}
	}
	catch (...) {
		return ErrorCodes::PRINT_CARDS_ERROR;
	}
	return 0;
}


int main(int argc, char * argv[]) {
	if (argc != NUM_ARGS) {
		return printUsageMessage(argv[0], USAGE_MESSAGE);
	}
	vector<PlayingCard> cardsVector;
	// Parse hands of cards from the text file
	int value = parseCardsFromFile(cardsVector, argv[1]);
	// Print out the type of each hand
	parseAndPrintHands(cardsVector);
	// Sort entire vector
	sort(cardsVector.begin(), cardsVector.end());
	// Print entire vector
	return printCardsVector(cardsVector);
	return ErrorCodes::FAILED_TO_TERMINATE;
}

