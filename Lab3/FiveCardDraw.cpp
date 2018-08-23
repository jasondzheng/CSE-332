#include "stdafx.h"
#include "PlayingCard.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Game.h"
#include "FiveCardDraw.h"
#include <sstream>
#include <fstream>
#include <set>
#include <algorithm>
#include <regex>

using namespace std;

FiveCardDraw::FiveCardDraw() : dealerPosition(0) {
	for (int i = Suits::clubs; i != Suits::spades; ++i) {
		for (int j = Ranks::two; j != Ranks::ace; ++j) {
			PlayingCard card(j, i);
			deck.addCard(card);
		}
	}
}


struct cmpStruct {
	bool operator() (int const & lhs, int const & rhs) const {
		return lhs > rhs;
	};
};

int FiveCardDraw::beforeTurn(Player & player) {
	cout << endl;
	cout << player.name << endl;
	cout << player.hand << endl;
	bool invalidInput = true;
	set<int, cmpStruct> toDelete;
	while (invalidInput) {
		cout << "Which cards would you like to discard?" << endl;
		string inputString;
		getline(cin, inputString);
		istringstream ss(inputString);
		string inputArgument;
		if (inputString == "all") {
			for (int i = 0; i < player.hand.size(); ++i) {
				toDelete.insert(i);
			}
			break;
		} else if (inputString == "none") {
			break;
		}
		bool allArgumentsValid = true;
		while (ss >> inputArgument) {
			int index;
			try {
				index = stoi(inputArgument);
			} catch (invalid_argument) {
				allArgumentsValid = false;
				break;
			}
			if (index < 0 || index >= player.hand.size() || !((toDelete.insert(index)).second)) {
				toDelete.clear();
				allArgumentsValid = false;
				break;
			}
		}
		invalidInput = !allArgumentsValid;
	}
	for (auto i = toDelete.begin(); i != toDelete.end(); i++) {
		discardDeck.addCard(player.hand[*i]);
		player.hand.removeCard(*i);
	}
	return 0;
}


int FiveCardDraw::turn(Player & player) {
	while (player.hand.size() < 5) {
		if (deck.size() > 0) {
			player.hand << deck;
		} else if (discardDeck.size() > 0) {
			discardDeck.shuffle();
			player.hand << discardDeck;
		} else {
			return 1;
		}
	}
	return 0;
}


int FiveCardDraw::afterTurn(Player & player) {
	cout << endl;
	cout << player.name << endl;
	cout << player.hand << endl;
	return 0;
}


int FiveCardDraw::beforeRound() {
	deck.shuffle();
	int dealStartIndex = (dealerPosition + 1);
	for (int i = 0; i < 5; ++i) {
		int index = dealStartIndex;
		for (int j = dealStartIndex; j < (int)players.size() + dealStartIndex; ++j) {
			(*players[j % players.size()]).hand << deck;
		}
	}
	for (int i = dealStartIndex; i < (int)players.size() + dealStartIndex; ++i) {
		beforeTurn(*players[i % players.size()]);
	}
	return 0;
}


int FiveCardDraw::round() {
	int dealStartIndex = (dealerPosition + 1);
	for (int i = dealStartIndex; i < (int)players.size() + dealStartIndex; ++i) {
		int turnFailed = turn(*players[i % players.size()]);
		if (turnFailed) {
			return turnFailed;
		}
		afterTurn(*players[i % players.size()]);
	}
	return 0;
}


bool pokerRank(shared_ptr<Player> player1, shared_ptr<Player> player2) {
	if (!player1) {
		return false;
	} else if (!player2) {
		return true;
	} else {
		return Hand::pokerRank((*player1).hand, (*player2).hand);
	}
}

int FiveCardDraw::afterRound() {
	vector<shared_ptr<Player>> tempPlayerVector = players;
	sort(tempPlayerVector.begin(), tempPlayerVector.end(), pokerRank);
	for (int i = 0; i < (int)tempPlayerVector.size(); ++i) {
		// TODO: check for multiple player wins.
		if (i == 0) {
			++(*tempPlayerVector[i]).handsWon;
		} else {
			++(*tempPlayerVector[i]).handsLost;
		}
		cout << endl;
		cout << "PLAYER: " << (*tempPlayerVector[i]).name << endl;
		cout << "WINS: " << (*tempPlayerVector[i]).handsWon << endl;
		cout << "LOSSES: " << (*tempPlayerVector[i]).handsLost << endl;
		cout << (*tempPlayerVector[i]).hand << endl;
	}

	for (int i = 0; i < (int)players.size(); ++i) {
		deck << (*players[i]).hand;
	}
	deck << discardDeck;
	
	cout << endl;

	while (true) {
		cout << "Would any players like to leave?" << endl;
		string inputString;
		cin >> inputString;
		if (inputString == "no") {
			break;
		}
		for (int i = 0; i < (int)players.size(); ++i) {
			if ((*players[i]).name == inputString) {
				ofstream playerFile((*players[i]).name, ofstream::out);
				playerFile << (*players[i]).name << " " << (*players[i]).handsWon << " " << (*players[i]).handsLost;
				cout << endl;
				playerFile.close();
				players.erase(players.begin() + i);
				break;
			}
		}
	}
	
	cout << endl;

	while (true) {
		cout << "Would any players like to join?" << endl;
		string inputString;
		cin >> inputString;
		cout << endl;
		if (inputString == "no") {
			break;
		}
		for (int i = 0; i < (int)players.size(); ++i) {
			try {
				if (!findPlayer(inputString)) {
					addPlayer(inputString);
				}
			} catch (...) {
				cout << "Player already exists" << endl;
			}
		}
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	dealerPosition = (dealerPosition + 1) % players.size();
	return 0;
}