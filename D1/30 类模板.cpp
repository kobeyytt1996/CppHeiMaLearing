#include <iostream>
#include <string>
using namespace std;

// ��ģ��

// �ͺ���ģ�������1. ��ģ��û���Զ��Ƶ�ʹ�÷�ʽ��2. ��ģ������б������Ĭ�ϲ���
// 
// ��ģ���г�Ա��������ʱ������ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ�������ģ��ĳ�Ա��������ʱ�Żᴴ��
//

template<class NameType, class AgeType = int>
class Person {
public:
	Person(NameType name, AgeType age);

	NameType m_Name;
	AgeType m_Age;
	// ��ģ���г�Ա�������������õ�ʱ�򶼲�֪���������ͣ���˲�����
	void showPerson() {
		cout << m_Name << m_Age << endl;
	}
};
// ��ģ���Ա��������ʵ�֣�����ǿ��T1��T2��ָPerson���
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	m_Name = name;
	m_Age = age;
}

// ��ģ���������������: 1. ָ����������: ���
void printPerson(Person<string, int>& p) {
	p.showPerson();
}
// 2. ����ģ�廯
template<class T1, class T2>
void printPerson1(Person < T1, T2>& p) {
	p.showPerson();
	// ����Ϊ��ȡ�����ķ�ʽ
	cout << typeid(T1).name() << endl;
	cout << typeid(T2).name() << endl;
}
// 3. ������ģ�廯
template<class T>
void printPerson2(T t) {
	t.showPerson();
	cout << typeid(T).name() << endl;
}

int main30() {
	Person<string, int> p1("sun", 99);
	Person<string> p2("sun", 99);

	printPerson(p1);
	printPerson1(p2);
	printPerson2(p2);

	return 0;
}