#include <iostream>
using namespace std;

// 深拷贝和浅拷贝（涉及有指针的成员属性，一定要自己构造深拷贝，尽量不要多个对象的成员指向同一内存区域)
// 浅拷贝：简单的赋值拷贝。编译器默认构造的。
// 深拷贝：在堆区重新申请空间，进行拷贝

// 初始化列表

class Per {
public:
	int m_Age;
	int* m_Height;
	int m_Salary;
	
	Per(int age, int height) {
		m_Age = age;
		m_Height = new int(height);
	}
	// 析构函数用于把堆区开辟的数据做释放
	~Per() {
		if (m_Height != NULL) {
			delete m_Height;
			// 防止野指针
			m_Height = NULL;
		}
	}
	// 深拷贝
	Per(const Per& p) {
		m_Age = p.m_Age;
		m_Height = new int(*p.m_Height);
	}

	// 初始化列表
	Per(int salary) :m_Age(10), m_Height(new int(30)), m_Salary(salary) {

	}
};

int main17() {
	// (用编译器构造的)浅拷贝带来的问题：堆区内存重复释放，因此出现异常
	Per p(10, 20);
	Per p1(p);
	Per p2(10);

	cout << *p2.m_Height << endl;

	return 0;
}