#pragma once // ��ֹͷ�ļ����ظ�����
#include <iostream>
using namespace std;

class Point {
public:
	int m_X;
	int m_Y;

	int calculateDistanceSquare(const Point& p1);
};