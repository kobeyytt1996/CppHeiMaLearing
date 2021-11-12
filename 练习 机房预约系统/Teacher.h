#pragma once
#include "Identity.h"
using namespace std;

class Teacher : public Identity {
public:
	int m_EmpID;

	Teacher();

	Teacher(int id, string name, string pwd);

	virtual void operMenu();

	void showAllOrder();

	void validOrder();
};