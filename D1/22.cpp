#include <iostream>
using namespace std;

// ���������
// �����������͵��������������֪���������

class Kobe {
	friend ostream& operator<<(ostream& cout, const Kobe& k);
public:
	int m_A;
	int m_B;

	Kobe(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}

	// ��Ա��������+��
	/*Kobe operator+(Kobe k) {
		Kobe temp(10, 20);
		temp.m_A = m_A + k.m_A;
		temp.m_B = this->m_B + k.m_B;
		return temp;
	}*/

	// �������������,�޷��ڳ�Ա���������أ���Ϊ�޷�ʵ��cout�ڸö�����ߵ�Ч��
	/*void operator<<() {

	}*/

	// ����ǰ��++��ע�ⷵ��ֵ�����ֶ�ͬһ������һֱ������
	Kobe& operator++() {
		m_C++;
		return *this;
	}

	// ���غ���++��ͨ��ռλ���ñ�����֪�����Ǻ���++��ֻ����int��ע���ǰ�õķ���ֵ��ͬ����Ϊ���Ǹ��ֲ�������
	Kobe operator++(int) {
		Kobe temp = *this;
		m_C++;
		return temp;
	}
private:
	int m_C;
};

// ȫ�ֺ�������+��
Kobe operator+(const Kobe& k1, const Kobe& k2) {
	Kobe temp(0, 0, 0);
	temp.m_A = k1.m_A + k2.m_A;
	temp.m_B = k1.m_B + k2.m_B;
	return temp;
}

// ��������أ�Ҳ���Է�����������
Kobe operator+(const Kobe& k1, int a) {
	Kobe temp(0, 0, 0);
	temp.m_B = k1.m_B + a;
	return temp;
}

// ȫ�ֺ�������<<��cout�Ǳ�׼���������ȫ��ֻ����һ������ֻ�����á���������Ϊ�˱�֤ʹ��ʱ��˳��һ�����ܷ�
// ע�ⷵ��ֵ����ʽ��̡�
ostream& operator<<(ostream& cout, const Kobe& k) {
	cout << k.m_A << endl << k.m_B << endl << k.m_C << endl;
	return cout;
}


int main22() {

	Kobe a(30, 40, 10);
	Kobe b(40, 70, 10);

	Kobe c = a + b;
	c++;
	cout << ++c << endl;

	return 0;
}