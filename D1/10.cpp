#include <iostream>
#include <string>
using namespace std;

// �ṹ�壬һЩ���͵ļ���

struct Student {
	string name;

	int age;

	int score;
} s3;

struct Teacher {
	string name;
	Student stu;
};



// ������Student����ĺ���������˳�����Ҫ��
void printStu(const Student* stu);

int main10() {
	// ���ִ�����ʽ������������֡�����ʱstruct����ʡ�ԡ�
	struct Student s1;
	struct Student s2 = { "����", 20, 100 };
	s3.age = 20;
	// �ṹ������
	struct Student stus[] = { {"����", 50, 100}, {"����", 20, 80 } };
	stus[1].age = 50;
	cout << sizeof(stus) << endl;

	// �ṹ��ָ�룬ʹ��->����������
	Student stu = { "����", 50, 100 };
	Student* stuP = &stu;
	stuP->age;

	Teacher tea[5];

	// �ṹ������������
	printStu(&stu);

	// �밴���������
	system("pause");
	// ����
	system("cls");

	return 0;
}

// ֵ���ݻ������ڴ濪��������ַ���ݲ��ᡣΪ�˷�ֹԭ�����ݱ��޸ģ����Լ���const��
void printStu(const Student* stu) {
	cout << stu->name << endl;
	return;
}