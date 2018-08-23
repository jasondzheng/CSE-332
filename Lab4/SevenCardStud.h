#pragma once
#ifndef SEVEN_CARD_STUD_H
#define SEVEN_CARD_STUD_H

#include "Player.h"
#include "Deck.h"
#include "Game.h"

class SevenCardStud : public Game {
protected:
	struct cmpStruct;
	size_t dealerPosition;
	Deck discardDeck;
	unsigned int pot;
	vector<shared_ptr<Player>> playersInRound;
	unsigned int highestBet;
	int betStartIndex;
public:
	SevenCardStud();
	int beforeTurn(Player &);
	int firstTurn(Player &);
	int turn(Player &);
	int lastTurn(Player &);
	int afterTurn(Player &);
	int beforeRound();
	int round();
	int afterRound();
	bool pokerRank(shared_ptr<Player>, shared_ptr<Player>);
	int askCheckOrBet(Player &);
	int askFoldCallOrRaise(Player &);
	int startBettingPhase();
	int resetBettingPhase();
	void displayCards(int);
};

#endif
