#include <iostream>
using namespace std;

// 模板：实现泛型编程，提高代码复用性
// 函数模板和类模板
// 
// 函数模板：
// 关键字：template --声明创建模板 typename --表明其后面的符号是一种数据类型，可以用class代替
// 目的是让类型参数化，使用时才确定

// 普通函数和函数模板的区别：普通函数可以发生自动类型转换（隐式类型转换）
// 函数模板只有显示指定类型才能发生自动类型转换

// 普通函数和函数模板的调用规则：最好不要同时出现
// 1. 如果函数模板和普通函数都可以调用，优先普通函数
// 2. 可以通过空模板参数列表强制调用函数模板: <>
// 3. 函数模板可以发生函数重载
// 4. 如果函数模板可以更好的匹配，优先函数模板

// 模板局限性：有些特定数据类型，需要用具体化方式做特殊实现

template<class T>
void swap29(T& t1, T& t2) {
	T temp = t1;
	t1 = t2;
	t2 = temp;
}

template<class T>
void func() {
	cout << "func" << endl;
}

template<class T>
bool myCompare(const T& a, const T& b) {
	return (a == b) ? true : false;
}

class Person {
public:
	int m_Age;
	Person(int age) {
		m_Age = age;
	}
};

// 利用具体化Person的版本实现代码，具体化优先调用
template<> bool myCompare(const Person& p1, const Person& p2) {
	return (p1.m_Age == p2.m_Age) ? true : false;
}

int main29() {
	double d1 = 10.0, d2 = 20.0;
	int i1 = 30;
	char c = 'c';
	float f1 = 5.1f;
	// 自动类型推导；编译器能根据调用时推导出来才可以
	swap29(d1, d2);
	// 显示指定类型：更建议用这种
	swap29<double>(d1, d2);
	func<int>();

	cout << d1 << "\t" << d2 << endl;
	Person p1(10);
	Person p2(20);
	cout << myCompare(p1, p2) << endl;
	return 0;
}