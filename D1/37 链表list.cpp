#include <iostream>
using namespace std;
#include <list>
#include <vector>
#include <algorithm>

// list��
// ռ�ÿռ��ͬ��size������󣬵����ö�̬�洢���䣬��������ڴ��˷�
// STL�е�������˫��ѭ������
// ��������˫�������

class Student {
public:
	int m_Age;
	int m_Height;

	Student(int age, int height) {
		m_Age = age;
		m_Height = height;
	}
};

void printList(const list<Student>& l) {
	for (list<Student>::const_iterator it = l.begin(); it != l.end(); ++it) {
		cout << it->m_Age << " " << it->m_Height << endl;
	}
}

void printList(const list<int>& l) {
	for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
		cout << *it << endl;
	}
}

template<class T>
bool myCompare(const T& t1, const T& t2) {
	return t1 < t2;
}

template<> bool myCompare(const Student& s1, const Student& s2) {
	if (s1.m_Age != s2.m_Age) {
		return s1.m_Age < s2.m_Age;
	}
	else {
		return s1.m_Height > s2.m_Height;
	}
}

int main37() {
	// ���캯����ͬ��������
	list<int> l1;
	list<int> l2(l1.begin(), l1.end());
	list<int> l3(l1);
	list<int> l4(10, 500);

	l2.push_back(20);
	l2.push_back(30);

	// ��ֵ�ͽ���
	l1 = l4;
	l4.assign(l1.begin(), l1.end());
	l4.assign(10, 5);
	l4.swap(l2);

	// ��С����
	l1.empty();
	l1.size();
	l1.resize(5);
	l1.resize(10, 800);

	// �����ɾ��
	l1.push_back(10);
	l1.push_front(20);
	l1.pop_back();
	l1.pop_front();
	l1.insert(++l1.begin(), 5);
	l1.erase(l1.begin());
	// list�½ӿڣ���ֵΪ800�Ķ��Ƴ�
	l1.remove(800);
	l1.clear();
	l1.swap(l2);

	// ���ݴ�ȡ
	l1.front() = 20;
	l1.back() = 200;

	// ��������֧��������ʣ�������it = it + 1

	// ��ת������
	l1.reverse();
	// ���в�֧��������ʵ��������������������ñ�׼�㷨���ڲ����ṩ�㷨
	// Ĭ��Ϊ���򣬿���ֱ�Ӵ��뺯��.
	l1.sort(myCompare<int>);

	list<Student> l5;
	l5.push_back(Student(20, 175));
	l5.push_back(Student(15, 160));
	l5.push_back(Student(15, 155));
	l5.push_back(Student(30, 180));
	// �����Զ����������ͣ����봫���жϺ����������رȽ������
	l5.sort(myCompare<Student>);

	printList(l5);
	return 0;
}