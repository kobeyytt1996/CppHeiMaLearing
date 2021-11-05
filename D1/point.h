#pragma once // 防止头文件被重复包含
#include <iostream>
using namespace std;

class Point {
public:
	int m_X;
	int m_Y;

	int calculateDistanceSquare(const Point& p1);
};