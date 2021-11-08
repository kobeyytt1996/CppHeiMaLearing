#include <iostream>
using namespace std;

// 对象模型和this指针

// 成员变量和成员函数分别存储
// 
// 只有非静态成员变量才属于类的对象上

// this指针：指向被调用的成员函数的所属对象，隐含在每一个非静态成员函数内的指针

// 空指针也可以调用成员函数，但如果用了this，（没有显示使用但是用了成员变量等也算），则会崩溃，需要判断来保持健壮性

class Curry {
public:
	int age;

	static int m_B;

	Curry(int age) {
		this->age = age;
	}

	Curry& func(int age) {
		this->age += age;
		return *this;
	}

	void show() {
		if (this != NULL) {
			cout << age << endl;
		}
		
	}

	static void func1() {}
};
int Curry::m_B = 20;


int main19() {
	Curry c(20);
	// 空对象占用空间为1字节：为了区分空对象占内存的位置，即每个空对象有独一无二的内存空间
	// 如果对象里有属性，则不再需要这个1字节
	cout << sizeof(c) << endl;

	// 链式编程，例如cout
	c.func(20).func(10);
	cout << c.age << endl;

	Curry* curry = NULL;
	curry->show();

	return 0;
}