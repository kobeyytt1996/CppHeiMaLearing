#include <iostream>
using namespace std;

class BasePage {
public:
	BasePage() {
		m_A = 100;
		cout << "BasePage����" << endl;
	}
	~BasePage() {
		cout << "BasePage����" << endl;
	}
	void header() {
		cout << "ͷ��" << endl;
	}
	void header(int a) {
		cout << "int a ͷ��" << endl;
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

// �̳�  
// ����Ҳ��Ϊ�����࣬�����Ϊ����
// �̳з�ʽ:����Ը����з�private�ĳ�Ա�ͺ���: public:����Ȩ�޺͸���һ�£�protected������Ϊprotected��private������Ϊprivate 

class Java : public BasePage {
public:
	// ͬ����Ա����
	int m_A;
	// ���ȵ��ø��๹�캯�����ٵ��������
	Java() {
		m_A = 200;
		cout << "Java����" << endl;
	}
	// ���������࣬����������
	~Java() {
		cout << "Java����" << endl;
	}
	void content() {
		cout << "Java" << endl;
	}
	// ͬ����Ա�����Ĵ���:�����г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա�����ص����������ͬ����Ա�����������������صģ���ͬ����̬��Ա����Ҳ��һ����
	void header() {

	}
	// ͬ����̬��Ա����
	static int m_S;
};
int Java::m_S = 200;

class Python : private BasePage {
public:
	void content() {
		cout << "Python" << endl;
	}
};

// ����C++������Ա������ʾ���߲鿴����ģ�ͣ�(�ڿ�ʼ�˵���vs�ļ�����)
// ��ת��ǰԴ�ļ�����·�����̷���e.g. D:
// cd ����·��
// cl /d1 reportSingleClassLayout���� Դ�ļ���
// e.g. cl /d1 reportSingleClassLayoutPython "24 �̳�.cpp"
int main24() {
	Java p;
	p.content();
	
	cout << sizeof(Python) << endl;
	// ���Ҫָ�����ʸ���ĳ�Ա�����Լ��� ��������::���ṩ������
	cout << p.m_A << endl;
	cout << p.BasePage::m_A << endl;

	p.header();
	p.BasePage::header(20);

	cout << p.m_S << endl;
	cout << p.BasePage::m_S << endl;
	cout << Java::m_S << endl;
	return 0;
}