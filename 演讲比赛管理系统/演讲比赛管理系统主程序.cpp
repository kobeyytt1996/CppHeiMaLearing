#include <iostream>
using namespace std;
#include "GameManager.h"
#include <ctime>

int mainSpeech() {
	GameManager gm;

	int choice;

	while (true)
	{
		srand((unsigned int)time(NULL));
		gm.showMenu();
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "»¶Ó­ÏÂ´Î¹âÁÙ" << endl;
			exit(0);
			break;
		case 1:
			gm.startGame();
			break;
		case 2:
			gm.showRecord();
			break;
		case 3:
			gm.clearRecord();
			break;
		default:
			break;
		}

		system("pause");
		system("cls");
	}

	return 0;
}