#include "Boss.h"
using namespace std;

Boss::Boss(int id, string name, int title) {
	this->m_ID = id;
	this->m_Name = name;
	this->title = title;
}

void Boss::showInfo() {
	cout << m_ID << "\t" << m_Name << "\t" << getTitle() << endl;
}

string Boss::getTitle() {
	return string("ÀÏ°å");
}