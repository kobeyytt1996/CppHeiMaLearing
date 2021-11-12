#pragma once
using namespace std;

class ComputerRoom {
public:
	int m_ID;
	int m_Capacity;

	ComputerRoom(int id, int cap) {
		m_ID = id;
		m_Capacity = cap;
	}
};