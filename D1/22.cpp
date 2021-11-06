#include <iostream>
using namespace std;

// 运算符重载
// 内置数据类型的运算符，编译器知道如何运算

class Kobe {
	friend ostream& operator<<(ostream& cout, const Kobe& k);
public:
	int m_A;
	int m_B;

	Kobe(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}

	// 成员函数重载+号
	/*Kobe operator+(Kobe k) {
		Kobe temp(10, 20);
		temp.m_A = m_A + k.m_A;
		temp.m_B = this->m_B + k.m_B;
		return temp;
	}*/

	// 重载左移运算符,无法在成员函数中重载，因为无法实现cout在该对象左边的效果
	/*void operator<<() {

	}*/

	// 重载前置++。注意返回值，保持对同一个对象一直递增。
	Kobe& operator++() {
		m_C++;
		return *this;
	}

	// 重载后置++。通过占位符让编译器知道这是后置++，只能用int。注意和前置的返回值不同，因为这是个局部变量。
	Kobe operator++(int) {
		Kobe temp = *this;
		m_C++;
		return temp;
	}
private:
	int m_C;
};

// 全局函数重载+号
Kobe operator+(const Kobe& k1, const Kobe& k2) {
	Kobe temp(0, 0, 0);
	temp.m_A = k1.m_A + k2.m_A;
	temp.m_B = k1.m_B + k2.m_B;
	return temp;
}

// 运算符重载，也可以发生函数重载
Kobe operator+(const Kobe& k1, int a) {
	Kobe temp(0, 0, 0);
	temp.m_B = k1.m_B + a;
	return temp;
}

// 全局函数重载<<。cout是标准输出流对象，全局只能有一个，故只能引用。两个参数为了保证使用时的顺序，一定不能反
// 注意返回值，链式编程。
ostream& operator<<(ostream& cout, const Kobe& k) {
	cout << k.m_A << endl << k.m_B << endl << k.m_C << endl;
	return cout;
}


int main22() {

	Kobe a(30, 40, 10);
	Kobe b(40, 70, 10);

	Kobe c = a + b;
	c++;
	cout << ++c << endl;

	return 0;
}