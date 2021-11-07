#include <iostream>
#include <string>
using namespace std;

// ���麯���ͳ�����
// ���������˴��麯���������Ҳ��Ϊ������
// �������ص㣺1. �޷�ʵ��������2. ���������д����Ĵ��麯������������Ҳ�ǳ�����

// �������ʹ�������
// ��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������
// Ϊ�˽��������Ҫ�������ʹ�������

class AbstractBase {
public:
	// ���麯����������� =0
	virtual void func() = 0;
	// ������������ͨ�麯����ͬ��������������������ʱҲ��ִ�е�
	/*virtual ~AbstractBase(){
		cout << "������" << endl;
	}*/
	// �����������ʹ��麯����ͬ����Ҫ����Ҳ��Ҫʵ�֡���Ϊ����Ҳ������Ҫ�ͷ��ڴ档����ʵ�֡����˴�������������Ҳ�ǳ����ࡣ
	virtual ~AbstractBase() = 0;
};
// ����ʵ�֣��ᱻִ�е���
AbstractBase::~AbstractBase() {
	cout << "��������" << endl;
}

class Son : public AbstractBase {
public:
	// ��д
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
		cout << "son ����" << endl;
	}
};

int main27() {
	
	AbstractBase* ab = new Son("ha");
	// ����ָ��������ʱ�򣬲����������������������������������ж���ָ�룬�����ڴ�й©���
	delete ab;

	return 0;
}