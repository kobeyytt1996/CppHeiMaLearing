#pragma once
#include <iostream>
#include "point.h"

class Circle {
public:
	Point center;
	int m_R;
public:
	string getPosition(const Point& p1);
};