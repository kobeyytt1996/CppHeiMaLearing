#include <iostream>
#include <vector>
#include <algorithm>
#include "Person.h"
using std::cout;
using std::endl;
using std::shared_ptr;
using std::vector;
using std::istream;
using std::make_shared;
using std::allocator;

class Window {
public:
	virtual void onResize() {
		cout << "Window" << endl;
	}
};

class SpecialWindow : public Window {
public:
	virtual void onResize() override {
		Window::onResize();
		cout << "SW" << endl;
	}
};

class Point {
public:
	Point(int x, int y) : xV(x), yV(y) {}

private:
	int xV, yV;
};

struct RecImpl
{
	Point ltc;
	Point rbc;
};

class Rec {
public:
	const Point& leftTop() const {
		return pRI->ltc;
	}
private:
	shared_ptr<RecImpl> pRI;
};

int doSth() noexcept;

class Image {
public:
	Image(istream &is) {}
};

struct PMImpl {
	shared_ptr<Image> bg;
	int imCh;
};

class PM {
public:
	void changeBg(istream &imgSrc) {
		shared_ptr<PMImpl> newPpi = make_shared<PMImpl>(*ppi);
		newPpi->bg.reset(new Image(imgSrc));
		++newPpi->imCh;

		using std::swap;
		swap(ppi, newPpi);
	}
private:
	shared_ptr<PMImpl> ppi;
};

template<typename T>
using Vec = vector<T, allocator<T>>;

class PM;

int main() {
	SpecialWindow sw;
	Window* window = &sw;
	window->onResize();

	typedef vector<shared_ptr<SpecialWindow>> VPSW;

	Person p;

	

	return EXIT_SUCCESS;
}