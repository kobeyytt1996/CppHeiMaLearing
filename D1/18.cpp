#include <iostream>
#include <string>
using namespace std;

// �������Ϊ���Ա

// ��̬��Ա��static
// ����׶ξͷ����ڴ棻���������������ʼ��; Ҳ�з���Ȩ��

class Phone {
public:
	Phone(string brand) :m_Brand(brand){}
	string m_Brand;

	// ��������
	static string os;

	static void getCPU() {
		os = "iOS";
		cout << os << endl;
	}
private:
	static int a;
};
// �����ʼ����::��ʾ�����򣬲���static��������������
int Phone::a = 10;
string Phone::os = "Android";

class Person {
public:
	Person(string name, string brand) :m_Name(name), m_Phone(brand) {}

	string m_Name;
	// �����Ա
	Phone m_Phone;
};

int main18() {

	Person p("yuan", "huawei");

	// ͨ��������з��ʾ�̬��Ա�����ͺ���
	cout << p.m_Phone.os << endl;
	// ͨ���������з��ʾ�̬��Ա�����ͺ���
	Phone::getCPU();
	cout << Phone::os << endl;
	return 0;
}