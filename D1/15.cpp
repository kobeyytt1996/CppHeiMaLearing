#include <iostream>
#include <string>

using namespace std;

const double PI = 3.14;
// ��Ͷ���
// ���������������ԣ���װ���̳кͶ�̬
// ���������Ժ���Ϊ

// 1. ��װ��1. ���Ժ���Ϊ��Ϊһ�����壬���������е����� 2. ���Ժ���Ϊ����Ȩ�޿���
// ���ԣ���Ա���Ի��Ա����
// ��Ϊ����Ա�������Ա����
class Circle {
	// ����Ȩ��
public:
	int m_r;
	double calculateZC() {
		return 2 * PI * m_r;
	}
};

class Student {
public:
	string m_Name;
	int m_Id;

	void setValue(string name, int id) {
		m_Name = name;
		m_Id = id;
	}

	void showValue() {
		cout << m_Name << " " << m_Id << endl;
	}
};

class Person {
public:
	string m_Name;
protected:
	string m_Car;
private:
	string m_Password;
};

// struct��class���ƣ���structĬ��Ȩ��public,class��Ϊprivate
struct ClassMate {
	int age;
};

// private�ô�:1. ���Կ��Ƴ�Ա�Ķ�дȨ�ޣ�����ֻ����д��ֻ��get����û��set����
// 2. ����д���Լ�����ݵ���Ч�ԡ�����set�������޶�����ֻ����0��100�ꡣ

// �Ѳ�ͬ����ŵ���ͬ��Դ�ļ���ͷ�ļ���ͷ�ļ������г�Ա�����ͳ�Ա������������
// Դ�ļ������г�Ա�����Ķ��壬�Һ�����ǰ�� ������::�����point��circle��Ӧ�ļ�


int main15() {
	// ʵ��������ͨ��һ���࣬����һ������Ĺ��̣�
	Circle circle1;
	circle1.m_r = 10;

	cout << circle1.calculateZC() << endl;

	Student stu;
	stu.setValue("yuan", 20);
	stu.showValue();

	
	return 0;
}