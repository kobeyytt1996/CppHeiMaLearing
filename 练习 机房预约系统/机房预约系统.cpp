#include <iostream>
#include <fstream>
#include "globalFile.h"
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
using namespace std;

void managerMenu(Identity*& manager) {
	while (true)
	{
		manager->operMenu();

		Manager* man = (Manager*)manager;
		int choice = 0;


		cin >> choice;

		switch (choice)
		{
		case 1:
			man->addPerson();
			break;
		case 2:
			man->showPerson();
			break;
		case 3:
			man->showComputer();
			break;
		case 4:
			man->cleanFile();
			break;
		case 0:
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			delete manager;
			manager = NULL;
			return;
			break;
		default:
			break;
		}


	}
}

void studentMenu(Identity*& student) {
	while (true)
	{
		student->operMenu();

		Student* man = (Student*)student;
		int choice = 0;


		cin >> choice;

		switch (choice)
		{
		case 1:
			man->applyOrder();
			break;
		case 2:
			man->showMyOrder();
			break;
		case 3:
			man->showAllOrder();
			break;
		case 4:
			man->cancelOrder();
			break;
		case 0:
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			delete student;
			student = NULL;
			return;
			break;
		default:
			break;
		}


	}
}

void loginIn(string fileName, int type) {
	ifstream ifs(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << "���������˺�" << endl;
		ifs.close();
		system("pause");
		return;
	}

	Identity* it = NULL;
	int id = 0;
	string name;
	string pwd;

	if (type == 1 || type == 2) {
		cout << "���ţ�" << endl;
		cin >> id;
	}
	cout << "������" << endl;
	cin >> name;
	cout << "����:" << endl;
	cin >> pwd;

	if (type == 1) {
		int tid;
		string tname;
		string tpwd;
		while (ifs >> tid && ifs >> tname && ifs >> tpwd) {
			if (id == tid && name == tname && pwd == tpwd) {
				cout << "ѧ����½�ɹ�" << endl;
				system("pause");
				system("cls");
				it = new Student(id, name, pwd);
				studentMenu(it);
				return;
			}
		}
	}
	else if (type == 2)
	{
		int tid;
		string tname;
		string tpwd;
		while (ifs >> tid && ifs >> tname && ifs >> tpwd) {
			if (id == tid && name == tname && pwd == tpwd) {
				cout << "��ʦ��½�ɹ�" << endl;
				system("pause");
				system("cls");
				it = new Teacher(id, name, pwd);

				return;
			}
		}
	}
	else
	{
		string tname;
		string tpwd;
		while (ifs >> tname && ifs >> tpwd) {
			if (name == tname && pwd == tpwd) {
				testAdmin:
				cout << "����Ա��½�ɹ�" << endl;
				system("pause");
				system("cls");
				it = new Manager(name, pwd);
				managerMenu(it);
				return;
			}
		}
	}

	cout << "��֤ʧ��" << endl;
	system("pause");
	system("cls");

	ifs.close();
}

int mainComputer() {
	int choice = 0;
	while (true) {
		cout << "1. ѧ��" << endl;
		cout << "2. ��ʦ" << endl;
		cout << "3. ����Ա" << endl;
		cout << "0. �˳�" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			loginIn(STUDENT_FILE, 1);
			break;
		case 2:
			loginIn(TEACHER_FILE, 2);
			break;
		case 3:
			loginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ" << endl;
			exit(0);
			break;
		default:
			cout << "����" << endl;
			system("pause");
			system("cls");
			break;
		}
	}


	return 0;
}