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
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	cout << "3.���" << endl;
	cout << "0.�˳�" << endl;

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
	cout << "��ǩ˳��" << endl;
	for_each(players.begin(), players.end(), printPlayerID);
	cout << endl;
}

void GameManager::startFirstRound() {
	cout << "��һ�ֿ�ʼ" << endl;
	setGrade(players.begin(), players.end());

	int half = PLAYERNUM / 2;
	vector<Player>::iterator middle = players.begin() + half;

	cout << "��1��ɼ���" << endl;
	sort(players.begin(), middle, comparePlayer);
	for_each(players.begin(), middle, PrintPlayer());

	cout << "��2��ɼ���" << endl;
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
	cout << "�ڶ��ֿ�ʼ" << endl;
	setGrade(players.begin(), players.end());
	cout << "�ڶ��ֳɼ���" << endl;
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
	cout << "�ɼ��ѱ���" << endl;
}

void GameManager::showRecord() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string ch;
	if (!ifs.is_open()) {
		cout << "��û�б���" << endl;
	}
	else {
		cout << "������ʷ�ɼ���" << endl;
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
	cout << "������¼�����" << endl;
}

