#include <iostream>
#include "Circle.h"
using namespace std;


string Circle::getPosition(const Point& p1) {
	int distanceS = center.calculateDistanceSquare(p1);
	if (distanceS < m_R*m_R) {
		return "��";
	}
	else if (distanceS > m_R*m_R) {
		return "��";
	}
	else
	{
		return "��";
	}
}
