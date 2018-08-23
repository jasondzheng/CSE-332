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

FiveCardDraw::FiveCardDraw() : dealerPosition(0), pot(0), highestBet(0), betStartIndex(0) {
	for (int i = Suits::clubs; i != Suits::spades; ++i) {
		for (int j = Ranks::two; j != Ranks::ace; ++j) {
			PlayingCard card(j, i);
			deck.addCard(card);
		}
	}
}


struct FiveCardDraw::cmpStruct {
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
		}
		else if (inputString == "none") {
			break;
		}
		bool allArgumentsValid = true;
		while (ss >> inputArgument) {
			int index;
			try {
				index = stoi(inputArgument);
			}
			catch (invalid_argument) {
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
		}
		else if (discardDeck.size() > 0) {
			discardDeck.shuffle();
			player.hand << discardDeck;
		}
		else {
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
	for (int i = dealStartIndex; i < (int)players.size() + dealStartIndex; ++i) {
		if ((*players[i % players.size()]).chips > 0) {
			--(*players[i % players.size()]).chips;
			++pot;
		}
	}
	for (int i = 0; i < 5; ++i) {
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
	// Betting phases setup
	playersInRound = players;
	betStartIndex = (dealerPosition + 1);
	// First betting phase
	if (startBettingPhase() == BettingPhaseOutcomes::roundShouldEnd) {
		return BettingPhaseOutcomes::roundShouldEnd;
	}
	// Deal Cards
	int dealStartIndex = (dealerPosition + 1);
	for (int i = dealStartIndex; i < (int)players.size() + dealStartIndex; ++i) {
		int turnFailed = turn(*players[i % players.size()]);
		if (turnFailed) {
			cout << "turnFailed" << endl;
			return turnFailed;
		}
		afterTurn(*players[i % players.size()]);
	}
	// Seond betting phase
	startBettingPhase();
	return 0;
}


bool FiveCardDraw::pokerRank(shared_ptr<Player> player1, shared_ptr<Player> player2) {
	if (!player1) {
		return false;
	}
	else if (!player2) {
		return true;
	}
	else {
		return Hand::pokerRank((*player1).hand, (*player2).hand);
	}
}

int FiveCardDraw::afterRound() {
	vector<shared_ptr<Player>> tempPlayerVector = playersInRound;
	sort(tempPlayerVector.begin(), tempPlayerVector.end(), [this](auto l, auto r) {return pokerRank(l, r); });
	for (int i = 0; i < (int)tempPlayerVector.size(); ++i) {
		// TODO: check for multiple player wins.
		if (i == 0) {
			++(*tempPlayerVector[i]).handsWon;
			(*tempPlayerVector[i]).chips += pot;
		}
		else {
			++(*tempPlayerVector[i]).handsLost;
		}
	}

	for (int i = 0; i < (int)players.size(); ++i) {
		cout << endl;
		cout << "PLAYER: " << (*players[i]).name << endl;
		cout << "CHIPS: " << (*players[i]).chips << endl;
		cout << "WINS: " << (*players[i]).handsWon << endl;
		cout << "LOSSES: " << (*players[i]).handsLost << endl;
		cout << (*players[i]).hand << endl;
		deck << (*players[i]).hand;
	}
	deck << discardDeck;

	resetBettingPhase();

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
				playerFile << (*players[i]).name << " " << (*players[i]).chips << " " << (*players[i]).handsWon << " " << (*players[i]).handsLost;
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
			}
			catch (...) {
				cout << "Player already exists" << endl;
			}
		}
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	dealerPosition = (dealerPosition + 1) % players.size();
	return 0;
}


int FiveCardDraw::askCheckOrBet(Player & player) {
	while (true) {
		try {
			cout << player.name << endl;
			cout << player.hand << endl;
			cout << "Bet? (check or input bet value)" << endl;
			string inputString;
			cin >> inputString;
			cout << endl;
			int betValue;
			if (inputString == "check") {
				return 1;
			}
			else if (betValue = stoi(inputString)) {
				if (betValue <= player.chips && (betValue == 1 || betValue == 2)) {
					player.chips -= betValue;
					pot += betValue;
					player.currBet = betValue;
					highestBet = betValue;
					return 0;
				}
			}
		} catch (...) {
			continue;
		}
	}
}


int FiveCardDraw::askFoldCallOrRaise(Player & player) {
	regex r("([0-9]+)", regex_constants::ECMAScript | regex_constants::icase);
	smatch match;
	while (true) {
		cout << player.name << endl;
		cout << player.hand << endl;
		cout << "fold, call, or input raise value (Highest bet: " << highestBet << ")" << endl;
		string inputString;
		cin >> inputString;
		cout << endl;
		int raiseValue;
		if (inputString == "fold") {
			return 1;
		}
		else if (inputString == "call") {
			int amountToAdd = highestBet - player.currBet;
			if (amountToAdd <= player.chips) {
				player.chips -= amountToAdd;
				pot += amountToAdd;
				player.currBet = highestBet;
				return 2;
			}
		}
		else if (regex_search(inputString, match, r)) {
			if ((raiseValue = stoi(match.str(1))) && (raiseValue == 1 || raiseValue == 2)) {
				int amountToAdd = highestBet + raiseValue - player.currBet;
				if (amountToAdd <= player.chips) {
					player.chips -= amountToAdd;
					pot += amountToAdd;
					player.currBet += amountToAdd;
					highestBet = player.currBet;
					return 0;
				}
			}
		}
	}
}


int FiveCardDraw::startBettingPhase() {
	cout << endl;
	int currHighestBet = highestBet;
	bool bettingPhaseShouldContinue = true;
	while (bettingPhaseShouldContinue) {
		int checkCount = 0;
		int callCount = 0;
		for (int i = 0; i < (int)playersInRound.size(); ++i) {
			int index = (betStartIndex + i) % playersInRound.size();
			if (highestBet != currHighestBet && highestBet == (*playersInRound[index]).currBet) {
				return BettingPhaseOutcomes::roundShouldContinue;
			}
			if (checkCount == playersInRound.size() || callCount == playersInRound.size()) {
				return BettingPhaseOutcomes::roundShouldContinue;
			}
			// Everyone but one folded
			if (playersInRound.size() == 1) {
				++(*playersInRound[0]).handsWon;
				(*playersInRound[0]).chips += pot;
				return BettingPhaseOutcomes::roundShouldEnd;
			}
			// Player has betted
			if (highestBet == 0) {
				checkCount += askCheckOrBet((*playersInRound[index]));
			} else {
				int value = askFoldCallOrRaise(*playersInRound[index]);
				if (value == 1) {
					playersInRound.erase(playersInRound.begin() + index);
					--i;
					if (i < dealerPosition) {
						--betStartIndex;
					}
				} else if (value == 2) {
					callCount++;
				}
			}
		}
	}
}


int FiveCardDraw::resetBettingPhase() {
	pot = 0;
	highestBet = 0;
	playersInRound = vector<shared_ptr<Player>>();
	for (int i = 0; i < players.size(); ++i) {
		(*players[i]).currBet = 0;
	}
	return 0;
}