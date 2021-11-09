#include <iostream>
#include <string>
using namespace std;


// 类模板与继承

// 类模板分文件编写: 在vs2019上可以和正常编写方式相同，更早的编译器上不可以
// 原因：类模板的函数在调用之前不创建，编译器就无法把头文件和源文件链接在一起，调用时就找不到源文件
// #include "Person.h"
// 解决方法1：直接去包含源文件：#include "Person.cpp"
// 解决方法2：头文件和源文件写在一起成hpp文件，别人一看就知道是类模板
#include "Person.hpp"

// 类模板与友元

// 为了让printbase1知道该类的存在
template<class T>
class Base;
// 需写在友元声明的前面，为了让编译器知道这个函数是模板函数
template<class T>
void printbase1(Base<T> b) {
	cout << b.m_base << endl;
}

template<class T>
class Base {
	// 全局函数，类内实现
	friend void printbase(Base<T> b) {
		cout << b.m_base << endl;
	}
	// 全局函数，类外实现（为了让编译器知道函数的实现，非常复杂(在上面)，建议类内实现)
	friend void printbase1<>(Base<T> b);
public:
	Base(T base) {
		m_base = base;
	}
	Base() {}
private:
	T m_base;
};

// 要么指定父类模板的类型，否则不知道分配多少内存
class Son : public Base<int> {
public:
	Son() {
		
	}
};
// 要么子类还是类模板
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