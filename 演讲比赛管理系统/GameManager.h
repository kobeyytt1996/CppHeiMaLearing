#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

using namespace std;

#define PLAYERNUM 12
#define BASEID 10000
#define scoreNum 10
#define WINNERNUM 3
#define FILENAME "SpeechGameRecord.csv"


class GameManager {
public:
	vector<Player> players;

	void showMenu();

	void startGame();

	void groupPlayers();

	void startFirstRound();

	void setGrade(vector<Player>::iterator start, vector<Player>::iterator end);

	void startSecondRound();

	void showRecord();

	void clearRecord();
};