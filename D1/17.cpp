#include <iostream>
using namespace std;

// �����ǳ�������漰��ָ��ĳ�Ա���ԣ�һ��Ҫ�Լ����������������Ҫ�������ĳ�Աָ��ͬһ�ڴ�����)
// ǳ�������򵥵ĸ�ֵ������������Ĭ�Ϲ���ġ�
// ������ڶ�����������ռ䣬���п���

// ��ʼ���б�

class Per {
public:
	int m_Age;
	int* m_Height;
	int m_Salary;
	
	Per(int age, int height) {
		m_Age = age;
		m_Height = new int(height);
	}
	// �����������ڰѶ������ٵ��������ͷ�
	~Per() {
		if (m_Height != NULL) {
			delete m_Height;
			// ��ֹҰָ��
			m_Height = NULL;
		}
	}
	// ���
	Per(const Per& p) {
		m_Age = p.m_Age;
		m_Height = new int(*p.m_Height);
	}

	// ��ʼ���б�
	Per(int salary) :m_Age(10), m_Height(new int(30)), m_Salary(salary) {

	}
};

int main17() {
	// (�ñ����������)ǳ�������������⣺�����ڴ��ظ��ͷţ���˳����쳣
	Per p(10, 20);
	Per p1(p);
	Per p2(10);

	cout << *p2.m_Height << endl;

	return 0;
}