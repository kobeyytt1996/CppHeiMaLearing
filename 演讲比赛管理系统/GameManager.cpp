#include "GameManager.h"
#include <algorithm>
#include <numeric>
#include <fstream>
using namespace std;

void printPlayerID(const Player& p) {
	cout << p.m_ID << " ";
}

bool comparePlayer(const Player& p1, const Player& p2) {
	return p1.m_AverageScore > p2.m_AverageScore;
}

class PrintPlayer {
public:
	int times;
	PrintPlayer() {
		times = 0;
	}
	void operator()(const Player& p) {
		++times;
		cout << times << " " << p.m_ID << " " << p.m_AverageScore << endl;
	}
};

void swap(Player& p1, Player& p2) {
	Player temp = p1;
	p1 = p2;
	p2 = temp;
}

void GameManager::showMenu() {
	cout << "1.比赛" << endl;
	cout << "2.往届" << endl;
	cout << "3.清空" << endl;
	cout << "0.退出" << endl;

}

void GameManager::startGame() {
	groupPlayers();
	system("pause");
	startFirstRound();
	system("pause");
	startSecondRound();
}

void GameManager::groupPlayers() {
	players.clear();
	for (int i = 1; i <= PLAYERNUM; ++i) {
		int ID = BASEID + i;
		players.push_back(Player(ID));
	}
	random_shuffle(players.begin(), players.end());
	cout << "抽签顺序：" << endl;
	for_each(players.begin(), players.end(), printPlayerID);
	cout << endl;
}

void GameManager::startFirstRound() {
	cout << "第一轮开始" << endl;
	setGrade(players.begin(), players.end());

	int half = PLAYERNUM / 2;
	vector<Player>::iterator middle = players.begin() + half;

	cout << "第1组成绩：" << endl;
	sort(players.begin(), middle, comparePlayer);
	for_each(players.begin(), middle, PrintPlayer());

	cout << "第2组成绩：" << endl;
	sort(middle, players.end(), comparePlayer);
	for_each(middle, players.end(), PrintPlayer());

	for (int i = 0; i < WINNERNUM; ++i) {
		vector<Player>::iterator loser = players.begin() + WINNERNUM + i;
		vector<Player>::iterator winner = middle + i;
		swap(*loser, *winner);
	}
	players.resize(PLAYERNUM / 2);
}

void GameManager::setGrade(vector<Player>::iterator start, vector<Player>::iterator end) {
	while (start != end)
	{
		start->scores.clear();
		for (int i = 0; i < scoreNum; ++i) {
			int score = rand() % 41 + 60;
			start->scores.push_back(score);
		}

		sort(start->scores.begin(), start->scores.end());
		start->scores.pop_back();
		start->scores.pop_front();
		start->m_AverageScore = accumulate(start->scores.begin(), start->scores.end(), 0) / start->scores.size();
		
		++start;
	}
}

void GameManager::startSecondRound() {
	cout << "第二轮开始" << endl;
	setGrade(players.begin(), players.end());
	cout << "第二轮成绩：" << endl;
	sort(players.begin(), players.end(), comparePlayer);
	for_each(players.begin(), players.end(), PrintPlayer());

	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::app);
	for (int i = 0; i < 3; ++i) {
		ofs << i + 1 << "," << players[i].m_ID << "," << players[i].m_AverageScore;
		if (i < 2) {
			ofs << ",";
		}
		else {
			ofs << endl;
		}
	}
	ofs.close();
	cout << "成绩已保存" << endl;
}

void GameManager::showRecord() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string ch;
	if (!ifs.is_open()) {
		cout << "还没有比赛" << endl;
	}
	else {
		cout << "比赛历史成绩：" << endl;
		while (ifs >> ch) {
			cout << ch;
		}
		cout << endl;
	}
}

void GameManager::clearRecord() {
	ofstream ofs;
	ofs.open(FILENAME, ios::trunc);
	ofs.close();
	cout << "比赛记录已清空" << endl;
}

