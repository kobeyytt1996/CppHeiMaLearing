#include "Manager.h"
using namespace std;

class EqualId {
public:
	int m_ID;
	EqualId(int id) {
		m_ID = id;
	}

	bool operator()(Student s) {
		return s.m_ID == m_ID;
	}

	bool operator()(Teacher t) {
		return t.m_EmpID == m_ID;
	}
};

class MyPrint {
public:

	void operator()(Student s) {
		cout << s.m_ID << " " << s.m_Name << endl;
	}

	void operator()(Teacher t) {
		cout << t.m_EmpID << " " << t.m_Name << endl;

	}
};

Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
	m_Name = name;
	m_Pwd = pwd;
	initVector();
	vCom.push_back(ComputerRoom(1, 20));
	vCom.push_back(ComputerRoom(2, 50));
	vCom.push_back(ComputerRoom(3, 100));
	cout << "����:" << vStu.size() << endl;

}

void Manager::operMenu() {
	cout << "1. ���" << endl;
	cout << "2. �˺�" << endl;
	cout << "3. ����" << endl;
	cout << "4. ���ԤԼ" << endl;
	cout << "0. ע��" << endl;
}


void Manager::addPerson() {
	cout << "ѧ��or��ʦ��" << endl;

	int choice;
	cin >> choice;

	string filename = (choice == 1) ? STUDENT_FILE : TEACHER_FILE;
	int id;
	string name, pwd;

	while (true) {
		cout << "���" << endl;
		cin >> id;
		if (checkRepeat(id, choice)) {
			cout << "�ñ���Ѵ���" << endl;
		}
		else {
			break;
		}
	}
	cout << "������" << endl;
	cin >> name;
	cout << "����: " << endl;
	cin >> pwd;

	ofstream ofs(filename, ios::out | ios::app);
	ofs << id << " " << name << " " << pwd << "\n";
	cout << "�洢�ɹ�" << endl;
	ofs.close();

	if (choice == 1) {
		vStu.push_back(Student(id, name, pwd));
	}
	else
	{
		vTea.push_back(Teacher(id, name, pwd));
	}

	system("pause");
	system("cls");
}

void Manager::showPerson() {
	cout << "ѧ��or��ʦ��" << endl;
	int choice;
	cin >> choice;

	if (choice == 1) {
		for_each(vStu.begin(), vStu.end(), MyPrint());
	}
	else {
		for_each(vTea.begin(), vTea.end(), MyPrint());
	}
}

void Manager::showComputer() {

}

void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;
}

void Manager::initVector() {
	ifstream ifs;
	int id;
	string name, pwd;

	ifs.open(STUDENT_FILE, ios::in);
	if (ifs.is_open()) {
		while (ifs >> id && ifs >> name && ifs >> pwd)
		{
			vStu.push_back(Student(id, name, pwd));
		}
	}
	ifs.close();
	ifs.open(TEACHER_FILE, ios::in);
	if (ifs.is_open()) {
		while (ifs >> id && ifs >> name && ifs >> pwd)
		{
			vTea.push_back(Teacher(id, name, pwd));
		}
	}

	cout << "ѧ��:" << vStu.size() << endl;
	cout << "��ʦ:" << vTea.size() << endl;

	ifs.close();
}

bool Manager::checkRepeat(const int& id, int type) {
	if (type == 1) {
		return find_if(vStu.begin(), vStu.end(), EqualId(id)) != vStu.end();
	}
	else {
		return find_if(vTea.begin(), vTea.end(), EqualId(id)) != vTea.end();
	}
}

