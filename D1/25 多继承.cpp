#include <iostream>
using namespace std;

// 多继承语法：实际开发中不建议

class BaseBase {
public:
	int m_Base;
};
// virtual表示虚继承，看下面的菱形继承，这时BaseBase称为虚基类
// 虚继承后存了vbptr（virtual base pointer),指向vbtable，那里记录了父类的数据。size上相当于增加了指针的内存。
class Base1 : virtual public BaseBase {
public:
	int m_A;
	Base1() {
		m_A = 100;
	}
};

class Base2 : virtual public BaseBase{
public:
	int m_A;
	Base2() {
		m_A = 20;
	}
};
// 多继承
// 且这里的Son是菱形继承，即它的两个基类又继承自同一个父类
// 菱形继承导致资源浪费：从两个父类都继承了一份父类的父类的数据，但实际上大多时候只需要一份
// 利用虚继承解决菱形继承的问题
// 可以用前一个源文件记录的工具查看Son的对象模型：他的两个父类都只存了vbptr（virtual base pointer),都指向vbtable，那里记录了父类父类的数据，因此只有一份
class Son : public Base1, public Base2 {
public:
	int m_C;
	Son() {
		m_C = 300;
	}
};


int main() {
	cout << sizeof(Base1) << endl;

	Son s;
	// 多继承的父类同名属性，也得加作用域区分
	cout << s.Base1::m_A << endl;
	// 菱形继承时，如果不用虚继承，想访问父类的父类的数据时
	s.Base1::m_Base = 20;
	// 菱形继承使用虚继承时，可以直接访问
	s.m_Base = 40;
	cout << s.Base2::m_Base << endl;

	return 0;
}