#include <iostream>
using namespace std;

void swap09(int* a, int* b);
void sort(int arr[], int len);

int main09() {
	double a = 10;
	double b = 30;

	// ָ�룺����һ����ַ
	double* p = &a;

	cout << p << endl;

	// ָ��ǰ��*Ϊ�����á����Խ��ж�д��
	*p = 1000.0;

	// 32λ������ָ�������趨�Ĳ���ϵͳ�����ǵ��Ի����������������x86����Ϊx64����ָ��4�ֽڣ�64λ��8�ֽ�
	cout << sizeof(p) << endl;

	// ��ָ�룺���ڸ�ָ��������г�ʼ����ָ���ڴ��б��Ϊ0�Ŀռ�
	// ��ָ�벻���Խ��з���:0~255֮����ڴ�����ϵͳռ�õģ���˲������û�����
	double* d = NULL;
	
	// Ұָ��:ָ��Ƿ����ڴ�ռ䡣�Ϳ�ָ�붼������������Ŀռ䣬��Ȩ���ʡ�
	int* p1 = (int*)0x1100;
	//cout << *p1 << endl;

	// const����ָ��
	// ����ָ�룺ָ��ָ����Ըģ�ָ��ָ���ֵ�����Ը�
	const double* cp = &a;
	// ָ�볣����ָ��ָ�򲻿��Ըģ�ָ��ָ���ֵ���Ը�
	double* const pc = &a;
	// ��ָ�볣���ֳ���ָ��
	const double* const cpc = NULL;

	// ָ�������
	int arr[10] = { 1, 2, 3 };
	// �õ��׵�ַ
	int* arrp = arr;
	// ��Ϊ��int��ָ�룬����++�������ƫ��4���ֽ�
	++arrp;
	cout << *arrp << endl;

	// ָ��ͺ���
	int num1 = 10, num2 = 20;
	swap09(&num1, &num2);
	cout << arr[1] << arr[2] << endl;

	int aii[] = { 5, 4, 3, 2, 1 };
	sort(aii, 5);
	for (int i = 0; i < 5; ++i) {
		cout << aii[i] << endl;
	}

	return 0;
}

// ��ַ���ݡ��ܸı�ʵ�ε�ֵ��
void swap09(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// ��һ������Ϊ�����׵�ַ��Ҳ����д��int arr[]�����ø�����
void sort(int* arr, int len) {
	for (int i = len - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}