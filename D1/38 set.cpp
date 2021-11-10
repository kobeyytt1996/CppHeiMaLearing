#include <iostream>
#include <set>
#include <string>
using namespace std;

// set������ʽ����
// �ײ��Ƕ�����
// set:���������ظ���multiset:�������ظ�

// �º������ڸ�set����ָ���������
class MyCompare38 {
public:
	// ��VS2019�У���ĺ���һ��Ҫ��const��������벻����
	// set��������const��������ȡ����º������󲢵���compare��������˱�����const
	bool operator()(int a, int b) const {
		return a > b;
	}
};

class Teacher38 {
public:
	Teacher38(string name) {
		m_Name = name;
	}
	string m_Name;
};

class MyCompare381 {
public:
	bool operator()(const Teacher38& t1, const Teacher38& t2) const {
		return (t1.m_Name.compare(t2.m_Name) == 1) ? true : false;
	}
};

void printSet(set<Teacher38, MyCompare381>& s) {
	for (set<Teacher38, MyCompare381>::iterator it = s.begin(); it != s.end(); ++it) {
		cout << it->m_Name << " ";
	}
	cout << endl;
}

int main38() {
	// ����
	set<int> s1;
	set<int> s2(s1);

	// ��������ֻ��insert��ʽ���������Զ����򡣷���ֵ��pair
	s1.insert(10);
	s1.insert(5);
	// p1.insert���ز���λ�ã�p1.second��ʾ�Ƿ����ɹ�
	pair<set<int>::iterator, bool> p1 = s1.insert(5);
	s2.insert(15);

	// ��С�ͽ���
	s1.size();
	s1.empty();
	s1.swap(s2);

	// ɾ�������˿��Ը�����ֵ��ɾ��Ԫ��
	s2.erase(s2.begin(), s2.end());
	s2.erase(10);
	s2.clear();

	// ���Һ�ͳ��
	// ���ص�������û���򷵻�s2.end()
	s2.find(15);
	// ����set�����ֻ������0��1
	s2.count(10);

	// multiset
	multiset<int> s3;
	s3.insert(10);
	s3.insert(5);
	s3.insert(20);
	// ֻ���ص�������û��bool�������ظ�����
	multiset<int>::iterator it3 = s3.insert(10);

	// pair������
	pair<string, int> p3("yy", 20);
	pair<string, int> p4 = make_pair("ww", 30);
	cout << p4.first << p4.second << endl;

	// set��������û������֮ǰ��Ҫ�޸���������÷º�����ָ����
	set<int, MyCompare38> s4;
	s4.insert(10);
	s4.insert(20);

	// ���������Զ����������ͣ����Ա���ָ���º���
	set<Teacher38, MyCompare381> s50;
	s50.insert(Teacher38("yy")); 
	s50.insert(Teacher38("zz"));

	printSet(s50);


	return 0;
}