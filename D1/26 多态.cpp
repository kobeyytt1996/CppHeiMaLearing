#include <iostream>
using namespace std;

// 多态：分为两类
// 静态重载：函数重载和运算符重载
// 动态重载：派生类和虚函数实现运行时多态
// 区别：编译阶段还是运行阶段确定函数地址

// 动态多态满足条件：1. 有继承关系；2. 子类要重写父类的虚函数
// 动态多态使用：父类的指针或引用指向子类对象

// 多态好处：1. 组织结构清晰，可读性强； 2. 扩展和维护性强，尽量不改以前的代码
// 真实开发中提倡开闭原则：对扩展进行开放，对修改进行关闭

class Animal {
public:
	// 虚函数实现运行时确定函数
	// 不加virtual时，Animal对象的size是1字节，加了以后是4字节，多了指针:vfptr,即虚函数(表)指针，指向vftable,虚函数表
	// 表内记录虚函数的地址
	virtual void speak() const {
		cout << "动物说" << endl;
	}
};

class Dog : public Animal {
public:
	// 可以不加virtual
	// 子类也获得vfptr，指向了自己的vftable。vftable里存的函数地址和父类一样，但当子类重写了父类的一个方法，子类的vftable内会替换成子类的虚函数地址。
	void speak() const {
		cout << "狗说" << endl;
	}
};

class Cat : public Animal {
public:
	void speak() const {
		cout << "猫说" << endl;
	}
};

// 引用或指针时：允许子类到父类的转换
// 如果不是虚函数即早绑定，编译阶段就确定了函数地址，只能执行Animal的对应方法
// 如果想让传入的实际对象调用对应函数，需要在运行阶段绑定，就要用虚函数
void doSpeak(const Animal& animal) {
	// 从子类的vftable里找
	animal.speak();
}

int main26() {
	Dog d;
	doSpeak(d);
	Cat c;
	doSpeak(c);
	cout << sizeof(Dog) << endl;

	return 0;
}