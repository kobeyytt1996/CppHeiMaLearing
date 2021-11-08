#include <iostream>
#include <string>

using namespace std;

const double PI = 3.14;
// 类和对象
// 面向对象的三大特性：封装、继承和多态
// 对象有属性和行为

// 1. 封装：1. 属性和行为作为一个整体，表现生活中的事物 2. 属性和行为加以权限控制
// 属性：成员属性或成员变量
// 行为：成员函数或成员方法
class Circle {
	// 公共权限
public:
	int m_r;
	double calculateZC() {
		return 2 * PI * m_r;
	}
};

class Student {
public:
	string m_Name;
	int m_Id;

	void setValue(string name, int id) {
		m_Name = name;
		m_Id = id;
	}

	void showValue() {
		cout << m_Name << " " << m_Id << endl;
	}
};

class Person {
public:
	string m_Name;
protected:
	string m_Car;
private:
	string m_Password;
};

// struct和class相似，但struct默认权限public,class则为private
struct ClassMate {
	int age;
};

// private好处:1. 可以控制成员的读写权限，比如只读不写，只有get方法没有set方法
// 2. 对于写可以检测数据的有效性。比如set方法里限定年龄只能在0到100岁。

// 把不同的类放到不同的源文件和头文件，头文件放所有成员变量和成员函数的声明，
// 源文件放所有成员函数的定义，且函数名前加 对象名::。详见point和circle对应文件


int main15() {
	// 实例化。（通过一个类，创建一个对象的过程）
	Circle circle1;
	circle1.m_r = 10;

	cout << circle1.calculateZC() << endl;

	Student stu;
	stu.setValue("yuan", 20);
	stu.showValue();

	
	return 0;
}