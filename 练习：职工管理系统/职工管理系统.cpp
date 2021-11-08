#include <iostream>
#include "workerManager.h"
#include "Employee.h"
#include "Boss.h"
using namespace std;


int mainZhigong() {
	WorkerManager wm;
	int select;
	while (true) {
		wm.showMenu();
		cin >> select;
		switch (select)
		{
		case 0:
			wm.exitSystem();
			break;
		case 1:
			wm.addWorker();
			break;
		case 2:
			wm.showWorker();
			break;
		case 3:
			wm.delWorker();
			break;
		case 4:
			wm.modWorker();
			break;
		case 5:
			break;
		case 6:
			wm.sortWorker();
			break;
		case 7:
			wm.clearData();
			break;
		default:
			break;
		}

		system("pause");
		system("cls");
	}

	return 0;
}