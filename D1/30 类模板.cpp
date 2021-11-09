#include <iostream>
#include <string>
using namespace std;

// 类模板

// 和函数模板的区别：1. 类模板没有自动推导使用方式；2. 在模板参数列表可以有默认参数
// 
// 类模板中成员函数创建时机：普通类中的成员函数一开始就可以创建，类模板的成员函数调用时才会创建
//

template<class NameType, class AgeType = int>
class Person {
public:
	Person(NameType name, AgeType age);

	NameType m_Name;
	AgeType m_Age;
	// 类模板中成员函数：不到调用的时候都不知道数据类型，因此不创建
	void showPerson() {
		cout << m_Name << m_Age << endl;
	}
};
// 类模板成员函数类外实现：必须强调T1，T2是指Person类的
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	m_Name = name;
	m_Age = age;
}

// 类模板对象作函数参数: 1. 指定传入类型: 最常用
void printPerson(Person<string, int>& p) {
	p.showPerson();
}
// 2. 参数模板化
template<class T1, class T2>
void printPerson1(Person < T1, T2>& p) {
	p.showPerson();
	// 以下为获取类名的方式
	cout << typeid(T1).name() << endl;
	cout << typeid(T2).name() << endl;
}
// 3. 整个类模板化
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