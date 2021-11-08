#include "Employee.h"
using namespace std;

Employee::Employee(int id, string name, int title) {
	this->m_ID = id;
	this->m_Name = name;
	this->title = title;
}

void Employee::showInfo() {
	cout << m_ID << "\t" << m_Name << "\t" << getTitle() << endl;
}

string Employee::getTitle() {
	return string("Ô±¹¤");
}