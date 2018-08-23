#pragma once
#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>
#include "Hand.h"
#include "Player.h"

using namespace std;

enum BettingPhaseOutcomes { roundShouldEnd = 0, roundShouldContinue };

class Game {
protected:
	static shared_ptr<Game> gamePointer;
	Deck deck;
	vector<shared_ptr<Player>> players;
public:
	static shared_ptr<Game> instance();
	static void startGame(const string &);
	static void stopGame();
	int numPlayers();
	void addPlayer(const string &);
	shared_ptr<Player> findPlayer(const string &);
	virtual ~Game();
	virtual int beforeTurn(Player &) = 0;
	virtual int turn(Player &) = 0;
	virtual int afterTurn(Player &) = 0;
	virtual int beforeRound() = 0;
	virtual int round() = 0;
	virtual int afterRound() = 0;
};

#endif