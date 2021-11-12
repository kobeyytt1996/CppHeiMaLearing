#pragma once
#include <iostream>
#include "Identity.h"

using namespace std;

class Student : public Identity {
public:
	int m_ID;

	Student();

	Student(int id, string name, string pwd);

	virtual void operMenu();

	void applyOrder();

	void showMyOrder();

	void showAllOrder();

	void cancelOrder();
};