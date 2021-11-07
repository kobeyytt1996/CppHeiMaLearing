#include <iostream>
#include <string>
using namespace std;

// 纯虚函数和抽象类
// 当类中有了纯虚函数，这个类也称为抽象类
// 抽象类特点：1. 无法实例化对象；2. 子类必须重写父类的纯虚函数，否则子类也是抽象类

// 虚析构和纯虚析构
// 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
// 为了解决，就需要虚析构和纯虚析构

class AbstractBase {
public:
	// 纯虚函数，函数后加 =0
	virtual void func() = 0;
	// 虚析构：和普通虚函数不同：下面这行在子类析构时也会执行到
	/*virtual ~AbstractBase(){
		cout << "虚析构" << endl;
	}*/
	// 纯虚析构：和纯虚函数不同，需要声明也需要实现。因为父类也可能需要释放内存。类外实现。有了纯虚析构，该类也是抽象类。
	virtual ~AbstractBase() = 0;
};
// 类外实现，会被执行到。
AbstractBase::~AbstractBase() {
	cout << "纯虚析构" << endl;
}

class Son : public AbstractBase {
public:
	// 重写
	void func() {
		cout << "func" << endl;
	}

	Son(string name) : m_Name(new string(name)) {}

	string* m_Name;

	~Son() {
		if (m_Name != NULL) {
			delete m_Name;
			m_Name = NULL;
		}
		cout << "son 析构" << endl;
	}
};

int main27() {
	
	AbstractBase* ab = new Son("ha");
	// 父类指针在析构时候，不会调用子类中析构函数，导致子类如果有堆区指针，出现内存泄漏情况
	delete ab;

	return 0;
}