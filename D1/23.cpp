#include <iostream>
#include <string>
using namespace std;

// 运算符重载：赋值
// 除了构造那里提到的三种，编译器还会给一个类默认生成赋值运算符，同拷贝构造函数函数，也是值拷贝。
// 如果成员对象有指向堆区的指针，我们就得重载赋值运算符为深拷贝。

class Green {
public:
	Green(int a) : m_A(new int(a)) {}
	~Green() {
		if (m_A != NULL) {
			delete m_A;
			m_A = NULL;
		}
	}

	int* m_A;
	// 赋值运算符重载。注意下面的判断细节
	Green& operator=(const Green& g1) {
		if (m_A != NULL) {
			delete m_A;
			m_A = NULL;
		}
		
		m_A = new int(*g1.m_A);
		return *this;
	}
	// 关系运算符重载
	bool operator==(const Green& g1) {
		if (g1.m_A != NULL && m_A != NULL) {
			return (*g1.m_A == *m_A) ? true : false;
		}
		return false;
	}

	// 函数调用运算符重载()
	// 重载后使用的方式非常像函数，因此叫仿函数，没有固定写法，所以灵活
	void operator()(string name) {
		cout << name << endl;
	}
};

int main() {
	Green p1(180);
	Green p2(200);
	Green p3(3200);
	p3 = p1 = p2;
	cout << (p3 == p2) << endl;

	// 仿函数的使用
	p1("Kobe");
	Green(300)("Curry");

	return 0;
}