#include <iostream>
#include "Student.h"

Student::Student() {

}

Student::Student(int id, string name, string pwd) {
	m_ID = id;
	m_Name = name;
	m_Pwd = pwd;
}

void Student::operMenu() {
	cout << "1. " << endl;
	cout << "2. " << endl;
	cout << "3. " << endl;
	cout << "4. " << endl;
	cout << "0. ×¢Ïú" << endl;
}

void Student::applyOrder() {

}

void Student::showMyOrder() {

}

void Student::showAllOrder() {

}

void Student::cancelOrder() {

}
