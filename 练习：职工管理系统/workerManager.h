#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

class WorkerManager {
public:
	WorkerManager();

	void showMenu();

	void exitSystem();

	~WorkerManager();

	int m_WorkerNum;

	Worker** m_WorkerArray;

	bool m_FileIsEmpty;

	void addWorker();

	void save();

	int getWorkerNum();

	void initWorker();

	void showWorker();

	int getWorker(int id);

	void delWorker();
};