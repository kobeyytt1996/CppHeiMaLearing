#include "workerManager.h"
#include <iostream>
#include "Boss.h"
#include "Employee.h"
#include <fstream>

using namespace std;

#define FILENAME "empFile.txt"

WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		m_WorkerNum = 0;
		m_WorkerArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	// 判断文件为空
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		m_WorkerNum = 0;
		m_WorkerArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	m_WorkerNum = getWorkerNum();
	if (m_WorkerNum > 0) {
		m_WorkerArray = new Worker * [m_WorkerNum];
		initWorker();
		for (int i = 0; i < m_WorkerNum; ++i) {
			cout << m_WorkerArray[i]->m_Name << endl;
		}
	}
}

void WorkerManager::showMenu() {
	cout << "0. 退出" << endl;
	cout << "1. 增加" << endl;
	cout << "2. 显示" << endl;
	cout << "3. 删除" << endl;
	cout << "4. 修改" << endl;
	cout << "5. 查找" << endl;
	cout << "6. 排序" << endl;
	cout << "7. 清空" << endl;
}

void WorkerManager::exitSystem() {
	cout << "欢迎下次" << endl;
	system("pause");
	exit(0);
}

WorkerManager::~WorkerManager() {
	if (m_WorkerArray != NULL) {
		delete[] m_WorkerArray;
		m_WorkerArray = NULL;
	}
}

void WorkerManager::addWorker() {
	cout << "加几个?" << endl;
	int num = 0;
	cin >> num;

	if (num <= 0) {
		cout << "输入有误" << endl;
	}
	else
	{
		int newSize = m_WorkerNum + num;
		if (m_WorkerArray == NULL) {
			m_WorkerArray = new Worker * [newSize];
		}
		else {
			Worker** newArray = new Worker * [newSize];
			for (int i = 0; i < m_WorkerNum; ++i) {
				newArray[i] = m_WorkerArray[i];
			}
			delete[] m_WorkerArray;
			m_WorkerArray = newArray;
		}

		for (int i = 0; i < num; ++i) {
			int id;
			string name;
			int title;

			cout << i + 1 << "姓名" << endl;
			cin >> name;

			cout << i + 1 << "编号" << endl;
			cin >> id;

			cout << i + 1 << "岗位" << endl;
			cin >> title;

			Worker* worker = NULL;
			if (title == 1) {
				worker = new Employee(id, name, title);
			}
			else {
				worker = new Boss(id, name, title);
			}

			m_WorkerArray[m_WorkerNum + i] = worker;
		}

		m_WorkerNum += num;
		m_FileIsEmpty = false;
		cout << "成功添加" << num << "名" << endl;

		save();
	}
}

void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < m_WorkerNum; ++i) {
		ofs << m_WorkerArray[i]->m_ID << " "
			<< m_WorkerArray[i]->m_Name << " "
			<< m_WorkerArray[i]->title << endl;
	}
	ofs.close();
}

int WorkerManager::getWorkerNum() {
	int num = 0;

	ifstream ifs(FILENAME, ios::in);

	int id;
	string name;
	int title;
	while (ifs >> id && ifs >> name && ifs >> title) {
		++num;
	}
	return num;
}

void WorkerManager::initWorker() {
	ifstream ifs(FILENAME, ios::in);

	int id;
	string name;
	int title;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> title) {
		Worker* worker;
		if (title == 1) {
			worker = new Employee(id, name, title);
		}
		else {
			worker = new Boss(id, name, title);
		}
		m_WorkerArray[index] = worker;

		++index;
	}

	ifs.close();
}

void WorkerManager::showWorker() {
	if (m_WorkerNum <= 0) {
		cout << "还没有职工" << endl;
	}
	else
	{
		for (int i = 0; i < m_WorkerNum; ++i) {
			m_WorkerArray[i]->showInfo();
		}
	}
}

int WorkerManager::getWorker(int id) {

}