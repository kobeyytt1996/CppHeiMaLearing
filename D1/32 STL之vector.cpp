#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

// stl��Ϊ�˽������ݽṹ���㷨��һ�ױ�׼
// standard template library:��׼ģ���
// ��Ϊ�����֣��������㷨�͵�����
// ����������������㷨�����������º�����������������������ռ�������

// vector

class Person {
public:
	int m_Age;
	string m_Name;
	Person(int age, string name) {
		m_Age = age;
		m_Name = name;
	}
};

void myPrint(int val) {
	cout << val << endl;
}

int main32() {

	vector<int> v;
	v.push_back(10);
	v.push_back(20);

	// ��ʼ�������ͽ��������������һ��Ԫ�ص���һ��λ��)
	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();

	// ��һ�ֱ�����ʽ
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}
	// �ڶ���
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}
	// ������ ע�����������ֱ�Ӵ��뺯����
	for_each(v.begin(), v.end(), myPrint);

	vector<Person> vP;
	vP.push_back(Person(10, "aa"));
	vP.push_back(Person(20, "bb"));
	for (vector<Person>::iterator it = vP.begin(); it != vP.end(); ++it) {
		cout << it->m_Age << it->m_Name << endl;
	}

	vector<Person*> vpp;
	vpp.push_back(new Person(10, "aa"));
	vpp.push_back(new Person(20, "bb"));
	
	// ����Ƕ������
	vector<vector<int>> vvi;
	vector<int> v11;
	v11.push_back(111);
	vector<int> v22;
	v22.push_back(222);

	vvi.push_back(v11);
	vvi.push_back(v22);

	for (vector<vector<int>>::iterator it = vvi.begin(); it != vvi.end(); ++it) {
		for (vector<int>::iterator itt = it->begin(); itt != it->end(); ++itt) {
			cout << *itt << endl;
		}
	}

	return 0;
}