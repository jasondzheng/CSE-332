#include "stdafx.h"
#include "Hand.h"
#include "Deck.h"
#include <algorithm>

using namespace std;

Hand::Hand() {
	cards = vector<PlayingCard>();
}

Hand::Hand(const Hand & hand) {
	cards = hand.cards;
}

Hand & Hand::operator=(const Hand & hand) {
	if (*this == hand) {
		return *this;
	}
	cards = hand.cards;
	return *this;
}

int Hand::size() const{
	return cards.size();
}

bool Hand::operator==(const Hand & hand) const {
	return cards == hand.cards;
}

bool Hand::operator<(const Hand & hand) const {
	for (int i = 0; i < min(cards.size(), hand.cards.size()); ++i) {
		if (!(cards[i] == hand.cards[i])) {
			return cards[i] < hand.cards[i];
		}
	}
	return cards.size() < hand.cards.size();
}

string Hand::asString() const {
	string result;
	for (int i = 0; i < cards.size(); ++i) {
		result += cards[i].toString() + " ";
	}
	return result;
}

int Hand::parseRank() const {
	bool sameSuit = true;
	bool consecutive = true;
	for (int i = 0; i < cards.size() - 1; ++i) {
		if (cards[i].rank != cards[i + 1].rank - 1) {
			consecutive = false;
		}
		if (cards[i].suit != cards[i + 1].suit) {
			sameSuit = false;
		}
	}
	if (sameSuit && consecutive) {
		return HandRanks::STRAIGHT_FLUSH;
	}
	else if (sameSuit && !consecutive) {
		return HandRanks::FLUSH;
	}
	else if (!sameSuit && consecutive) {
		return HandRanks::STRAIGHT;
	}

	vector<int> occurrences;
	int sum = 1;
	int currRank = NULL;
	for (int i = 0; i < cards.size(); ++i) {
		if (currRank == cards[i].rank) {
			++sum;
		}
		else if (i == 0) {
			currRank = cards[i].rank;
		}
		else {
			occurrences.push_back(sum);
			currRank = cards[i].rank;
			sum = 1;
		}
	}
	occurrences.push_back(sum);

	if (occurrences.size() == 2) {
		if (occurrences[0] == 1 || occurrences[0] == 4) {
			return HandRanks::FOUR_OF_A_KIND;
		}
		else {
			return HandRanks::FULL_HOUSE;
		}
	}

	if (occurrences.size() == 3) {
		if (occurrences[0] == 3 || occurrences[1] == 3 || occurrences[2] == 3) {
			return HandRanks::THREE_OF_A_KIND;
		}
		else {
			return HandRanks::TWO_PAIRS;
		}
	}

	if (occurrences.size() == 4) {
		return HandRanks::ONE_PAIR;
	}

	return HandRanks::NO_RANK;
}

vector<int> Hand::getComparisonVector(int handRank) const {
	vector<int> groups;
	vector<int> singles;
	switch (handRank) {
	case HandRanks::NO_RANK:
		for (int i = cards.size() - 1; i >= 0; --i) {
			singles.push_back(cards[i].rank);
		}
		return singles;
		break;
	case HandRanks::ONE_PAIR:
		for (int i = cards.size() - 1; i >= 0; --i) {
			if (i != 0 && cards[i].rank == cards[i - 1].rank) {
				groups.push_back(cards[i].rank);
				--i;
			} else {
				singles.push_back(cards[i].rank);
			}
		}
		groups.insert(groups.end(), singles.begin(), singles.end());
		return groups;
		break;
	case HandRanks::TWO_PAIRS:
		for (int i = cards.size() - 1; i >= 0; --i) {
			if (i != 0 && cards[i].rank == cards[i - 1].rank) {
				groups.push_back(cards[i].rank);
				--i;
			}
			else {
				singles.push_back(cards[i].rank);
			}
		}
		groups.insert(groups.end(), singles.begin(), singles.end());
		return groups;
		break;
	case HandRanks::THREE_OF_A_KIND:
		for (int i = cards.size() - 1; i >= 2; --i) {
			if (cards[i].rank == cards[i - 1].rank && cards[i - 1].rank == cards[i - 2].rank) {
				groups.push_back(cards[i].rank);
				return groups;
			}
		}
		return groups;
		break;
	case HandRanks::STRAIGHT:
		singles.push_back(cards.back().rank);
		return singles;
		break;
	case HandRanks::FLUSH:
		for (int i = cards.size() - 1; i >= 0; --i) {
			singles.push_back(cards[i].rank);
		}
		return singles;
		break;
	case HandRanks::FULL_HOUSE:
		if (cards[4].rank == cards[3].rank && cards[3].rank == cards[2].rank) {
			groups.push_back(cards[4].rank);
			groups.push_back(cards[0].rank);
		} else {
			groups.push_back(cards[0].rank);
			groups.push_back(cards[4].rank);
		}
		return groups;
		break;
	case HandRanks::FOUR_OF_A_KIND:
		if (cards[4].rank == cards[3].rank) {
			groups.push_back(cards[4].rank);
		} else {
			groups.push_back(cards[0].rank);
		}
		return groups;
		break;
	case HandRanks::STRAIGHT_FLUSH:
		singles.push_back(cards.back().rank);
		return singles;
		break;
	}
}

ostream & operator<<(ostream & os, const Hand & hand) {
	os << hand.asString() << " ";
	return os;
}

void operator<<(Hand & hand, Deck & deck) {
	if (deck.cards.size() > 0) {
		PlayingCard card = deck.cards.back();
		deck.cards.pop_back();
		hand.cards.push_back(card);
		sort(hand.cards.begin(), hand.cards.end());
	} else {
		cout << "No more cards in deck" << endl;
	}
}