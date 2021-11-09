#include <iostream>
#include <string>

template<class T>
class MyArray {
public:
	T* m_Array;
	int m_Capacity;
	int m_Size;

	MyArray(int cap) {
		m_Capacity = cap;
		m_Array = new T[m_Capacity];
		m_Size = 0;
	}

	~MyArray() {
		if (m_Array != NULL) {
			delete[] m_Array;
			m_Array = NULL;
		}
	}

	MyArray(const MyArray& arr) {
		m_Capacity = arr.m_Capacity;
		m_Size = arr.m_Size;
		m_Array = new T[m_Capacity];
		for (int i = 0; i < m_Size; ++i) {
			m_Array[i] = arr.m_Array[i];
		}
	}

	MyArray& operator=(const MyArray& arr) {
		if (m_Array != NULL) {
			delete[] m_Array;
		}

		m_Capacity = arr.m_Capacity;
		m_Size = arr.m_Size;
		m_Array = new T[m_Capacity];
		for (int i = 0; i < m_Size; ++i) {
			m_Array[i] = arr.m_Array[i];
		}

		return *this;
	}

	T& operator[](int i) {
		if (i > m_Size) {
			cout << "数组下标越界" << endl;
		}
		else
		{
			return m_Array[i];
		}
	}

	void addLast(const T& t) {
		if (m_Size + 1 > m_Capacity) {
			m_Capacity *= 2;
			T* temp = new T[m_Capacity];
			for (int i = 0; i < m_Size; ++i) {
				temp[i] = m_Array[i];
			}

			delete[] m_Array;
			m_Array = temp;
		}

		m_Array[m_Size] = t;
		++m_Size;
	}

	void delLast() {
		if (m_Size == 0) {
			cout << "数组为空" << endl;
		}
		else {
			m_Size--;
		}
	}
};