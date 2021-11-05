#include <iostream>
#include <string>
using namespace std;

// 类对象作为类成员

// 静态成员：static
// 编译阶段就分配内存；类内声明，类外初始化; 也有访问权限

class Phone {
public:
	Phone(string brand) :m_Brand(brand){}
	string m_Brand;

	// 类内声明
	static string os;

	static void getCPU() {
		os = "iOS";
		cout << os << endl;
	}
private:
	static int a;
};
// 类外初始化，::表示作用域，不加static，但加数据类型
int Phone::a = 10;
string Phone::os = "Android";

class Person {
public:
	Person(string name, string brand) :m_Name(name), m_Phone(brand) {}

	string m_Name;
	// 对象成员
	Phone m_Phone;
};

int main18() {

	Person p("yuan", "huawei");

	// 通过对象进行访问静态成员变量和函数
	cout << p.m_Phone.os << endl;
	// 通过类名进行访问静态成员变量和函数
	Phone::getCPU();
	cout << Phone::os << endl;
	return 0;
}