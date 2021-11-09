#include <iostream>
#include <string>

template<class T>
class MyArray {
public:
	T* m_Array = new T[];
};