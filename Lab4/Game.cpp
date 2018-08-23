#include "stdafx.h"
#include "Game.h"
#include "FiveCardDraw.h"
#include "SevenCardStud.h"

using namespace std;

struct InstanceNotAvailableException : public runtime_error {
	InstanceNotAvailableException(string const& message) : runtime_error(message + " was thrown") {};
};

struct GameAlreadyStartedException : public runtime_error {
	GameAlreadyStartedException(string const& message) : runtime_error(message + " was thrown") {};
};

struct UnknownGameException : public runtime_error {
	UnknownGameException(string const& message) : runtime_error(message + " was thrown") {};
};

struct NoGameInProgressException : public runtime_error {
	NoGameInProgressException(string const& message) : runtime_error(message + " was thrown") {};
};

struct AlreadyPlayingException : public runtime_error {
	AlreadyPlayingException(string const& message) : runtime_error(message + " was thrown") {};
};


shared_ptr<Game> Game::gamePointer;


shared_ptr<Game> Game::instance() {
	try {
		if (gamePointer) {
			return gamePointer;
		} else {
			throw InstanceNotAvailableException("InstanceNotAvailableException");
		}
	} catch (InstanceNotAvailableException) {
		cout << "Instance not available" << endl;
	}
}


void Game::startGame(const string & startString) {
	try {
		if (gamePointer) {
			throw GameAlreadyStartedException("GameAlreadyStartedException");
		} else if (startString.find("FiveCardDraw") != string::npos) {
			gamePointer = make_shared<FiveCardDraw>();
		} else if (startString.find("SevenCardStud") != string::npos) {
			gamePointer = make_shared<SevenCardStud>();
		} else {
			throw UnknownGameException("UnkownGameException");
		}
	} catch (GameAlreadyStartedException) {
		cout << "Game already started" << endl;
	} catch (UnknownGameException) {
		cout << "Unknown game" << endl;
	}
}


void Game::stopGame() {
	try {
		if (gamePointer) {
			gamePointer.reset();
		} else {
			throw NoGameInProgressException("NoGameInProgressException");
		}
	} catch (NoGameInProgressException) {
		cout << "No game in progress" << endl;
	}
}


int Game::numPlayers() {
	return players.size();
}


void Game::addPlayer(const string & name) {
	try {
		if (findPlayer(name)) {
			throw AlreadyPlayingException("AlreadyPlayingException");
		} else {
			players.push_back(make_shared<Player>(name));
		}
	} catch (AlreadyPlayingException) {
		cout << "Player already playing" << endl;
	}
}


shared_ptr<Player> Game::findPlayer(const string & name) {
	for (int i = 0; i < players.size(); ++i) {
		if ((*players[i].get()).name == name) {
			return players[i];
		}
	}
	return shared_ptr<Player>();
}


Game::~Game() = default;

