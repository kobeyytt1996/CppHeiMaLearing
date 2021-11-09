#include <iostream>
#include <string>
using namespace std;


// ��ģ����̳�

// ��ģ����ļ���д: ��vs2019�Ͽ��Ժ�������д��ʽ��ͬ������ı������ϲ�����
// ԭ����ģ��ĺ����ڵ���֮ǰ�����������������޷���ͷ�ļ���Դ�ļ�������һ�𣬵���ʱ���Ҳ���Դ�ļ�
// #include "Person.h"
// �������1��ֱ��ȥ����Դ�ļ���#include "Person.cpp"
// �������2��ͷ�ļ���Դ�ļ�д��һ���hpp�ļ�������һ����֪������ģ��
#include "Person.hpp"

// ��ģ������Ԫ

// Ϊ����printbase1֪������Ĵ���
template<class T>
class Base;
// ��д����Ԫ������ǰ�棬Ϊ���ñ�����֪�����������ģ�庯��
template<class T>
void printbase1(Base<T> b) {
	cout << b.m_base << endl;
}

template<class T>
class Base {
	// ȫ�ֺ���������ʵ��
	friend void printbase(Base<T> b) {
		cout << b.m_base << endl;
	}
	// ȫ�ֺ���������ʵ�֣�Ϊ���ñ�����֪��������ʵ�֣��ǳ�����(������)����������ʵ��)
	friend void printbase1<>(Base<T> b);
public:
	Base(T base) {
		m_base = base;
	}
	Base() {}
private:
	T m_base;
};

// Ҫôָ������ģ������ͣ�����֪����������ڴ�
class Son : public Base<int> {
public:
	Son() {
		
	}
};
// Ҫô���໹����ģ��
template<class T, class T2>
class Son2 : public Base<T> {
public:
	T2 t2;
};



int main31() {
	/*Son s1;*/
	Son2<string, int> s2;

	Person<string, int> p1("yuan", 19);
	p1.showPerson();

	Base<int> b1(20);
	printbase(b1);
	printbase1(b1);

	return 0;
}