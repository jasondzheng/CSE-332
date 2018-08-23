#pragma once
#ifndef FIVE_CARD_DRAW_H
#define FIVE_CARD_DRAW_H

#include "Player.h"
#include "Deck.h"
#include "Game.h"

class FiveCardDraw : public Game {
protected:
	struct cmpStruct;
	size_t dealerPosition;
	Deck discardDeck;
	unsigned int pot;
	vector<shared_ptr<Player>> playersInRound;
	unsigned int highestBet;
	int betStartIndex;
public:
	FiveCardDraw();
	int beforeTurn(Player &);
	int turn(Player &);
	int afterTurn(Player &);
	int beforeRound();
	int round();
	int afterRound();
	bool pokerRank(shared_ptr<Player>, shared_ptr<Player>);
	int askCheckOrBet(Player &);
	int askFoldCallOrRaise(Player &);
	int startBettingPhase();
	int resetBettingPhase();
};

#endif
