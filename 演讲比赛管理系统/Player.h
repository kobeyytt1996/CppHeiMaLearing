#pragma once
#include <deque>
using namespace std;

class Player {
public:
	int m_ID;
	int m_AverageScore;
	deque<int> scores;

	Player(int ID) {
		m_ID = ID;
		m_AverageScore = 0;
	}

	Player() {
		m_ID = 0;
		m_AverageScore = 0;
	}
};