#include <iostream>
using namespace std;

// const���γ�Ա���������ͳ�����

class Warrior {
public:
	int m_A;
	// �������������޸ĳ�Ա����.����mutable���εĳ�Ա����
	// this��ָ�볣���������const�൱�ڼ�����thisǰ�棬thisָ���ֵҲ�����޸�
	void change(int a) const {
		m_B = a;
	}
	// �������
	mutable int m_B;


};

int main20() {
	// �����󡣲����޸����Ա������ֵ��ֻ���޸�mutable�޸ĵġ�
	const Warrior warrior;
	// ������ֻ�ܵ��ó���������Ϊ��ȷ�����������Ƿ���޸ĳ�Ա������
	warrior.m_B = 10;

	return 0;
}