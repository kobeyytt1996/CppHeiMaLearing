#include <iostream>
#include <string>
using namespace std;

int main06() {
	// ���飺����һ���������ڴ�ռ䣬ÿ��Ԫ�ض�����ͬ�������͡�
	// ���ֶ��巽ʽ��
	int arr[] = { 1, 2, 3 };
	int arr1[5];
	int arr2[2] = { 1, 2 };

	// һά����������;��1. ͳ�������������ڴ��еĳ��ȣ�sizeof��
	// 2. ��ȡ�������ڴ��е��׵�ַ,16���Ʊ�ʾ����intǿת���Ա��ʮ������ʾ��&��ȡַ���š�
	bool barr[] = { true, 100 };
	cout << (int)&barr[1] << endl;
	// �������Ǹ��������������¸�ֵ
	//barr = { false };

	// ��ά���飺���ֶ��巽ʽ�������ֲ��á�����ʡ����������Ϊ���������Ը����������Ʋ⡣
	int irr0[2][3];
	int irr1[2][3] = { {1, 2, 3}, {2, 3, 4} };
	int irr2[2][3] = { 1, 2, 3, 2, 3, 4 };
	int irr3[][4] = { 1, 2, 3, 4, 5 };

	int scores[3][3] = { {100, 100, 100}, {90, 50 ,100}, {60, 70, 80} };
	for (int i = 0; i < sizeof(scores) / sizeof((scores[0])); ++i) {
		int sum = 0;
		for (int j = 0; j < sizeof(scores[0]) / sizeof(scores[0][0]); ++j) {
			sum += scores[i][j];
		}
		cout << sum << endl;
	}

	return 0;
}