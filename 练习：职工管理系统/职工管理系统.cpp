#include <iostream>
#include "workerManager.h"
#include "Employee.h"
#include "Boss.h"
using namespace std;


int main() {
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
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			break;
		}

		system("pause");
		system("cls");
	}

	return 0;
}