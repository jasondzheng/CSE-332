#pragma once
#ifndef FIVE_CARD_DRAW_H
#define FIVE_CARD_DRAW_H

#include "Player.h"
#include "Deck.h"
#include "Game.h"

class FiveCardDraw : public Game {
protected:
	size_t dealerPosition;
	Deck discardDeck;
public:
	FiveCardDraw();
	int beforeTurn(Player &);
	int turn(Player &);
	int afterTurn(Player &);
	int beforeRound();
	int round();
	int afterRound();
};

#endif