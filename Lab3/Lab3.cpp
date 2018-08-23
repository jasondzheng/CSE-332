// Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"

using namespace std;

int main(int argc, char * argv[]) {
	if (argc < 4) {
		cout << "The program should be run with the name of a game followed by the names of two or more players" << endl;
		return 1;
	}

	Game::startGame(argv[1]);

	shared_ptr<Game> game = Game::instance();

	for (int i = 2; i < argc; ++i) {
		(*game).addPlayer(argv[i]);
	}

	while ((*game).numPlayers() > 1) {
		if ((*game).beforeRound()) {
			Game::stopGame();
			return 2;
		} else if ((*game).round()) {
			Game::stopGame();
			return 3;
		} else if ((*game).afterRound()) {
			Game::stopGame();
			return 4;
		}
	}

    return 0;
}

