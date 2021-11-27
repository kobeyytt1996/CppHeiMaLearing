//#pragma once
//#include <string>
//#include <vector>
//#include <iostream>
//
//int height;
//const int ci = 20;
//
//class Window {
//public:
//	using ScreenType = std::vector<int>::size_type;
//	std::vector<Screen> screens{ Screen(10, 20, ' ') };
//
//	Screen screen{ 10, 20, 'a' };
//
//	ScreenType get();
//};
//
//class Screen {
//	// friend class Window;
//	friend Window::ScreenType Window::get();
//public:
//	using pos = std::string::size_type;
//
//	Screen() = default;
//
//	Screen(pos wd, pos ht, char c) : width(wd), height(ht), contents(wd*ht, c) {}
//
//	char get() const {
//		++count;
//		return contents[cursor];
//	}
//
//	inline char get(pos ht, pos wd) const;
//
//	const Screen& move(pos r, pos c) const {
//		return *this;
//	}
//
//	const Screen& display() const {
//		do_display();
//		return *this;
//	}
//
//	Screen& display() {
//		do_display();
//		return *this;
//	}
//
//private:
//	pos cursor = 0;
//	pos height = 0, width = 0;
//	std::string contents;
//	mutable pos count = 0;
//
//	void do_display() const {
//
//	}
//};
//
//char Screen::get(pos ht, pos wd) const {
//	::height;
//	return ' ';
//}
//
//Window::ScreenType Window::get() {
//	screen.cursor;
//}
//
//class Y;
//
//class X {
//	Y* yPtr;
//};
//
//class Y {
//	X m_x;
//};
//
//typedef double Money;
//class Accout {
//public:
//	typedef double Money;
//};