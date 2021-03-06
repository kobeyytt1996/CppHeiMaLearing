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
		for (int i = 0; i < m_WorkerNum; ++i) {
			delete m_WorkerArray[i];
		}
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
	for (int i = 0; i < m_WorkerNum; ++i) {
		if (m_WorkerArray[i]->m_ID == id) {
			return i;
		}
	}

	return -1;
}

void WorkerManager::delWorker() {
	if (m_WorkerNum <= 0) {
		cout << "还没有职工" << endl;
		return;
	}
	else
	{
		int delNum;
		cout << "编号：" << endl;
		cin >> delNum;
		int index = getWorker(delNum);

		if (index == -1) {
			cout << "该职工不存在" << endl;
		}
		else {
			delete m_WorkerArray[index];
			for (int i = index; i < m_WorkerNum - 1; ++i) {
				m_WorkerArray[i] = m_WorkerArray[i + 1];
			}

			m_WorkerNum--;
			m_WorkerArray[m_WorkerNum] = NULL;

			if (m_WorkerNum == 0) {
				m_FileIsEmpty = true;
			}

			save();
			cout << "已成功删除" << endl;
		}
	}
}

void WorkerManager::modWorker() {
	if (m_WorkerNum <= 0) {
		cout << "还没有职工" << endl;
		return;
	}
	else
	{
		int modNum;
		cout << "编号：" << endl;
		cin >> modNum;
		int index = getWorker(modNum);

		if (index == -1) {
			cout << "该职工不存在" << endl;
		}
		else {
			delete m_WorkerArray[index];
			int id;
			string name;
			int title;

			cout << "姓名" << endl;
			cin >> name;
			cout << "编号" << endl;
			cin >> id;
			cout << "职位" << endl;
			cin >> title;

			if (title == 1) {
				m_WorkerArray[index] = new Employee(id, name, title);
			}
			else {
				m_WorkerArray[index] = new Boss(id, name, title);
			}

			save();
			cout << "已成功修改" << endl;
		}
	}
}

void WorkerManager::sortWorker() {
	if (m_WorkerNum <= 0) {
		cout << "还没有职工" << endl;
		return;
	}
	else {
		// 选择排序
		int maxTemp, maxTempIndex;
		for (int i = 0; i < m_WorkerNum; ++i) {
			maxTempIndex = i;
			maxTemp = m_WorkerArray[i]->m_ID;
			for (int j = i + 1; j < m_WorkerNum; ++j) {
				if (m_WorkerArray[j]->m_ID > maxTemp) {
					maxTemp = m_WorkerArray[j]->m_ID;
					maxTempIndex = j;
				}
			}

			if (maxTempIndex != i) {
				Worker* temp = m_WorkerArray[i];
				m_WorkerArray[i] = m_WorkerArray[maxTempIndex];
				m_WorkerArray[maxTempIndex] = temp;
			}
		}


		save();
		cout << "已成功排序" << endl;
	}
}

void WorkerManager::clearData() {
	if (m_WorkerNum > 0) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		for (int i = 0; i < m_WorkerNum; ++i) {
			delete m_WorkerArray[i];
		}
		m_WorkerNum = 0;
		delete[] m_WorkerArray;
		m_WorkerArray = NULL;
		m_FileIsEmpty = true;
		
		cout << "已清空" << endl;
	}
	
}