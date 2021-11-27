#pragma once
#include <string>
#include <vector>

class Screen {
public:
	using pos = std::string::size_type;

	Screen() = default;

	Screen(pos wd, pos ht, char c) : width(wd), height(ht), contents(wd*ht, c) {}

	char get() const {
		++count;
		return contents[cursor];
	}

	inline char get(pos ht, pos wd) const;

	Screen& move(pos r, pos c);

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	mutable pos count = 0;
};

class Window {
public:
	std::vector<Screen> screens{ Screen(10, 20, ' ') };

	Screen screen{ 10, 20, 'a' };
};