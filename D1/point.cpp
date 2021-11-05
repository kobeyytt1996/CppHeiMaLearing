#include <iostream>
#include "point.h"

int Point::calculateDistanceSquare(const Point& p1) {
	return (p1.m_X - m_X) * (p1.m_X - m_X) + (p1.m_Y - m_Y) * (p1.m_Y - m_Y);
}
