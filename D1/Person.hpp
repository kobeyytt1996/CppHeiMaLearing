#pragma once
#include <iostream>
#include <string>
using namespace std;

template<class NameType, class AgeType = int>
class Person {
public:
	Person(NameType name, AgeType age);

	NameType m_Name;
	AgeType m_Age;
	// 类模板中成员函数：不到调用的时候都不知道数据类型，因此不创建
	void showPerson();
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	m_Name = name;
	m_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson() {
	cout << m_Name << m_Age << endl;
}