#include <iostream>
#include "swap.h"
using namespace std;

// �����������Ͷ���
// ��������ǰ���߱����������Ĵ��ڡ�
// ���������ж�Σ�����ֻ����һ��
int max(int a, int b);

// �����Ķ��ļ���д��1. ͷ�ļ����� 2. Դ�ļ����壬Դ�ļ�#include "swap.h"�����߱�������ͷ�ļ��Ĺ�ϵ 3. ʹ�ô�Ҳ����ͷ�ļ�

int main08() {
	swap02(10, 20);
	return 0;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}