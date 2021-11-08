#include <iostream>
using namespace std;

// ģ�壺ʵ�ַ��ͱ�̣���ߴ��븴����
// ����ģ�����ģ��
// 
// ����ģ�壺
// �ؼ��֣�template --��������ģ�� typename --���������ķ�����һ���������ͣ�������class����
// Ŀ���������Ͳ�������ʹ��ʱ��ȷ��

// ��ͨ�����ͺ���ģ���������ͨ�������Է����Զ�����ת������ʽ����ת����
// ����ģ��ֻ����ʾָ�����Ͳ��ܷ����Զ�����ת��

// ��ͨ�����ͺ���ģ��ĵ��ù�����ò�Ҫͬʱ����
// 1. �������ģ�����ͨ���������Ե��ã�������ͨ����
// 2. ����ͨ����ģ������б�ǿ�Ƶ��ú���ģ��: <>
// 3. ����ģ����Է�����������
// 4. �������ģ����Ը��õ�ƥ�䣬���Ⱥ���ģ��

// ģ������ԣ���Щ�ض��������ͣ���Ҫ�þ��廯��ʽ������ʵ��

template<class T>
void swap29(T& t1, T& t2) {
	T temp = t1;
	t1 = t2;
	t2 = temp;
}

template<class T>
void func() {
	cout << "func" << endl;
}

template<class T>
bool myCompare(const T& a, const T& b) {
	return (a == b) ? true : false;
}

class Person {
public:
	int m_Age;
	Person(int age) {
		m_Age = age;
	}
};

// ���þ��廯Person�İ汾ʵ�ִ��룬���廯���ȵ���
template<> bool myCompare(const Person& p1, const Person& p2) {
	return (p1.m_Age == p2.m_Age) ? true : false;
}

int main29() {
	double d1 = 10.0, d2 = 20.0;
	int i1 = 30;
	char c = 'c';
	float f1 = 5.1f;
	// �Զ������Ƶ����������ܸ��ݵ���ʱ�Ƶ������ſ���
	swap29(d1, d2);
	// ��ʾָ�����ͣ�������������
	swap29<double>(d1, d2);
	func<int>();

	cout << d1 << "\t" << d2 << endl;
	Person p1(10);
	Person p2(20);
	cout << myCompare(p1, p2) << endl;
	return 0;
}