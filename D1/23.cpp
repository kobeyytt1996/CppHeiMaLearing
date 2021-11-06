#include <iostream>
#include <string>
using namespace std;

// ��������أ���ֵ
// ���˹��������ᵽ�����֣������������һ����Ĭ�����ɸ�ֵ�������ͬ�������캯��������Ҳ��ֵ������
// �����Ա������ָ�������ָ�룬���Ǿ͵����ظ�ֵ�����Ϊ�����

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
	// ��ֵ��������ء�ע��������ж�ϸ��
	Green& operator=(const Green& g1) {
		if (m_A != NULL) {
			delete m_A;
			m_A = NULL;
		}
		
		m_A = new int(*g1.m_A);
		return *this;
	}
	// ��ϵ���������
	bool operator==(const Green& g1) {
		if (g1.m_A != NULL && m_A != NULL) {
			return (*g1.m_A == *m_A) ? true : false;
		}
		return false;
	}

	// �����������������()
	// ���غ�ʹ�õķ�ʽ�ǳ���������˽зº�����û�й̶�д�����������
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

	// �º�����ʹ��
	p1("Kobe");
	Green(300)("Curry");

	return 0;
}