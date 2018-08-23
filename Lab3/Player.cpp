#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

Player::Player(string playerName) : name(playerName), handsWon(0), handsLost(0) {
	ifstream playerFile(playerName);
	if (playerFile.good()) {
		string stat;
		regex r("[0-9]+", regex_constants::ECMAScript | regex_constants::icase);
		int count = 0;
		int validCount = 0;
		while ((playerFile >> stat) && (count < 3)) {
			switch (count) {
			case 0:
				name = stat;
				++validCount;
				break;
			case 1:
				if (regex_match(stat, r)) {
					handsWon = stoi(stat);
					++validCount;
				}
				break;
			case 2:
				if (regex_match(stat, r)) {
					handsLost = stoi(stat);
					++validCount;
				}
				break;
			}
			++count;
		}
		if (validCount != 3) {
			name = playerName;
			handsWon = 0;
			handsLost = 0;
		}
	}
};

ostream & operator<<(ostream & os, const Player & player) {
	os << "PLAYER: " << player.name << endl;
	os << "WINS: " << player.handsWon << endl;
	os << "LOSSES: " << player.handsLost << endl;
	return os;
}
