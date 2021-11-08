#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker {
public:
	int m_ID;
	string m_Name;
	int title;

	virtual void showInfo() = 0;

	virtual string getTitle() = 0;
};