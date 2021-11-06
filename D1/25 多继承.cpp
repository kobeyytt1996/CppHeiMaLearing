#include <iostream>
using namespace std;

// ��̳��﷨��ʵ�ʿ����в�����

class BaseBase {
public:
	int m_Base;
};
// virtual��ʾ��̳У�����������μ̳У���ʱBaseBase��Ϊ�����
// ��̳к����vbptr��virtual base pointer),ָ��vbtable�������¼�˸�������ݡ�size���൱��������ָ����ڴ档
class Base1 : virtual public BaseBase {
public:
	int m_A;
	Base1() {
		m_A = 100;
	}
};

class Base2 : virtual public BaseBase{
public:
	int m_A;
	Base2() {
		m_A = 20;
	}
};
// ��̳�
// �������Son�����μ̳У����������������ּ̳���ͬһ������
// ���μ̳е�����Դ�˷ѣ����������඼�̳���һ�ݸ���ĸ�������ݣ���ʵ���ϴ��ʱ��ֻ��Ҫһ��
// ������̳н�����μ̳е�����
// ������ǰһ��Դ�ļ���¼�Ĺ��߲鿴Son�Ķ���ģ�ͣ������������඼ֻ����vbptr��virtual base pointer),��ָ��vbtable�������¼�˸��ุ������ݣ����ֻ��һ��
class Son : public Base1, public Base2 {
public:
	int m_C;
	Son() {
		m_C = 300;
	}
};


int main() {
	cout << sizeof(Base1) << endl;

	Son s;
	// ��̳еĸ���ͬ�����ԣ�Ҳ�ü�����������
	cout << s.Base1::m_A << endl;
	// ���μ̳�ʱ�����������̳У�����ʸ���ĸ��������ʱ
	s.Base1::m_Base = 20;
	// ���μ̳�ʹ����̳�ʱ������ֱ�ӷ���
	s.m_Base = 40;
	cout << s.Base2::m_Base << endl;

	return 0;
}