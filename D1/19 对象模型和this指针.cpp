#include <iostream>
using namespace std;

// ����ģ�ͺ�thisָ��

// ��Ա�����ͳ�Ա�����ֱ�洢
// 
// ֻ�зǾ�̬��Ա������������Ķ�����

// thisָ�룺ָ�򱻵��õĳ�Ա��������������������ÿһ���Ǿ�̬��Ա�����ڵ�ָ��

// ��ָ��Ҳ���Ե��ó�Ա���������������this����û����ʾʹ�õ������˳�Ա������Ҳ�㣩������������Ҫ�ж������ֽ�׳��

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
	// �ն���ռ�ÿռ�Ϊ1�ֽڣ�Ϊ�����ֿն���ռ�ڴ��λ�ã���ÿ���ն����ж�һ�޶����ڴ�ռ�
	// ��������������ԣ�������Ҫ���1�ֽ�
	cout << sizeof(c) << endl;

	// ��ʽ��̣�����cout
	c.func(20).func(10);
	cout << c.age << endl;

	Curry* curry = NULL;
	curry->show();

	return 0;
}