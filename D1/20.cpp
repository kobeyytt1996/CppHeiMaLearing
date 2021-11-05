#include <iostream>
using namespace std;

// const修饰成员：常函数和常对象

class Warrior {
public:
	int m_A;
	// 常函数：不能修改成员变量.除非mutable修饰的成员变量
	// this是指针常量，下面的const相当于加在了this前面，this指向的值也不可修改
	void change(int a) const {
		m_B = a;
	}
	// 特殊变量
	mutable int m_B;


};

int main20() {
	// 常对象。不可修改其成员变量的值，只能修改mutable修改的。
	const Warrior warrior;
	// 常对象只能调用常函数。因为不确定其他函数是否会修改成员变量。
	warrior.m_B = 10;

	return 0;
}