#include <iostream>
using namespace std;

// ��̬����Ϊ����
// ��̬���أ��������غ����������
// ��̬���أ���������麯��ʵ������ʱ��̬
// ���𣺱���׶λ������н׶�ȷ��������ַ

// ��̬��̬����������1. �м̳й�ϵ��2. ����Ҫ��д������麯��
// ��̬��̬ʹ�ã������ָ�������ָ���������

// ��̬�ô���1. ��֯�ṹ�������ɶ���ǿ�� 2. ��չ��ά����ǿ������������ǰ�Ĵ���
// ��ʵ�������ᳫ����ԭ�򣺶���չ���п��ţ����޸Ľ��йر�

class Animal {
public:
	// �麯��ʵ������ʱȷ������
	// ����virtualʱ��Animal�����size��1�ֽڣ������Ժ���4�ֽڣ�����ָ��:vfptr,���麯��(��)ָ�룬ָ��vftable,�麯����
	// ���ڼ�¼�麯���ĵ�ַ
	virtual void speak() const {
		cout << "����˵" << endl;
	}
};

class Dog : public Animal {
public:
	// ���Բ���virtual
	// ����Ҳ���vfptr��ָ�����Լ���vftable��vftable���ĺ�����ַ�͸���һ��������������д�˸����һ�������������vftable�ڻ��滻��������麯����ַ��
	void speak() const {
		cout << "��˵" << endl;
	}
};

class Cat : public Animal {
public:
	void speak() const {
		cout << "è˵" << endl;
	}
};

// ���û�ָ��ʱ���������ൽ�����ת��
// ��������麯������󶨣�����׶ξ�ȷ���˺�����ַ��ֻ��ִ��Animal�Ķ�Ӧ����
// ������ô����ʵ�ʶ�����ö�Ӧ��������Ҫ�����н׶ΰ󶨣���Ҫ���麯��
void doSpeak(const Animal& animal) {
	// �������vftable����
	animal.speak();
}

int main26() {
	Dog d;
	doSpeak(d);
	Cat c;
	doSpeak(c);
	cout << sizeof(Dog) << endl;

	return 0;
}