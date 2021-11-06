#include <iostream>
using namespace std;

class BasePage {
public:
	BasePage() {
		m_A = 100;
		cout << "BasePage构造" << endl;
	}
	~BasePage() {
		cout << "BasePage析构" << endl;
	}
	void header() {
		cout << "头部" << endl;
	}
	void header(int a) {
		cout << "int a 头部" << endl;
	}
	int m_A;
	static int m_S;
	static int getS() {
		return m_S;
	}
protected:
	int m_B;
private:
	int m_C;
};
int BasePage::m_S = 20;

// 继承  
// 子类也称为派生类，父类称为基类
// 继承方式:均针对父类中非private的成员和函数: public:访问权限和父类一致；protected：都变为protected；private：都变为private 

class Java : public BasePage {
public:
	// 同名成员变量
	int m_A;
	// 会先调用父类构造函数，再调用子类的
	Java() {
		m_A = 200;
		cout << "Java构造" << endl;
	}
	// 先析构子类，再析构父类
	~Java() {
		cout << "Java析构" << endl;
	}
	void content() {
		cout << "Java" << endl;
	}
	// 同名成员函数的处理:子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类的所有同名成员函数（包括各种重载的）。同名静态成员函数也是一样。
	void header() {

	}
	// 同名静态成员变量
	static int m_S;
};
int Java::m_S = 200;

class Python : private BasePage {
public:
	void content() {
		cout << "Python" << endl;
	}
};

// 利用C++开发人员命令提示工具查看对象模型：(在开始菜单的vs文件夹下)
// 跳转当前源文件所在路径的盘符，e.g. D:
// cd 绝对路径
// cl /d1 reportSingleClassLayout类名 源文件名
// e.g. cl /d1 reportSingleClassLayoutPython "24 继承.cpp"
int main24() {
	Java p;
	p.content();
	
	cout << sizeof(Python) << endl;
	// 如果要指定访问父类的成员，可以加上 父类名字::，提供作用域
	cout << p.m_A << endl;
	cout << p.BasePage::m_A << endl;

	p.header();
	p.BasePage::header(20);

	cout << p.m_S << endl;
	cout << p.BasePage::m_S << endl;
	cout << Java::m_S << endl;
	return 0;
}