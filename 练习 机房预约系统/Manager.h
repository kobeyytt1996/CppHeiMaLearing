#pragma once
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "ComputerRoom.h"
using namespace std;

class Manager : public Identity {
public:
	Manager();

	Manager(string name, string pwd);

	virtual void operMenu();

	void addPerson();

	void showPerson();

	void showComputer();

	void cleanFile();

	vector<Student> vStu;

	vector<Teacher> vTea;

	vector<ComputerRoom> vCom;

	void initVector();

	bool checkRepeat(const int& id, int type);
};