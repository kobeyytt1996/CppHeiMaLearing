#include <iostream>
#include <string>
#include "Circle.h"
using namespace std;

// 对象的初始化和清理
// 构造函数和析构函数

class Person {
public:
	int age;
	// 构造函数：分类：1. 按参数：有参和无参 2. 按类型：普通构造和拷贝构造
	Person() {
		// 不写编译器也会帮我们生成无参的一个空实现，默认构造
		cout << "构造函数" << endl;
	}

	Person(int a) {
		age = a;
	}

	// 拷贝构造,把p的属性完全复制过来
	// 三种调用时机：1. 用一个创建好的对象初始化新对象 2. 值传递的方式传参 3. 值方式返回局部对象
	Person(const Person& p) {
		age = p.age;
		cout << "拷贝" << age << endl;
	}
	
	// 析构函数：~构造函数; 不可以有参数，编译器在对象销毁前自动调用，且只调用一次。
	~Person() {
		cout << "析构" << this->age << endl;
	}
};

// 默认下，c++编译器给一个类增加三个：默认无参构造函数，默认无参析构函数，默认拷贝构造函数
// 用户定义有普通构造函数，则编译器还会生成拷贝构造函数；
// 定义有拷贝构造函数(或其他任何构造函数)，编译器不会生成无参构造函数。
class Player {
public:
	~Player() {

	}
	Player(int a) {

	}
};


int main16() {
	
	// 构造函数自动调用
	
	// 调用方法：
	// 1. 括号法。 注意：调用默认构造函数的时候，不要加()，会被认为是一个函数的声明。
	Person p;
	Person p2(30);
	Person p3(p2);

	// 2. 显示法。等号右面是匿名对象：其特点：单独写出时，当前行执行结束后，立马被释放。下面这种不会。
	Person p4 = Person(50);
	Person p5 = Person(p4);
	// 不要利用拷贝构造函数初始化匿名对象，编译器认为Person(p4) === Person p4;从而导致重名
	/*Person(p5);*/

	// 3. 隐式转换法
	// 编译器作转换为对应构造函数
	Person p6 = 100;
	Person p7 = p6;

	
	return 0;
}