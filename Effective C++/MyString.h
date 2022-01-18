#pragma once
#include <string>
using std::string;

class MyString {
private:
	char* _data;
	size_t _len;
	void _init_data(const char* s) {
		_data = new char[_len + 1];
		memcpy(_data, s, _len);
		_data[_len] = '\0';
	}

public:
	MyString(const char *p = nullptr) : _data(nullptr), _len(0) {
		if (p) {
			_len = strlen(p);
			_init_data(p);
		}
	}

	MyString(const MyString& ms) : _data(nullptr), _len(ms._len) {
		_init_data(ms._data);
	}

	MyString& operator=(const MyString& ms) {
		MyString temp = ms;
		delete[] _data;
		_data = temp._data;
	}

	MyString(MyString&& ms) noexcept : _data(ms._data), _len(ms._len) {
		ms._data = nullptr;
		ms._len = 0;
	}
};