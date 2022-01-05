#include <iostream>
#include <mutex>
using std::mutex;
using std::cout;
using std::endl;
using std::shared_ptr;

void lock(mutex* pm) {
	cout << "lock" << endl;
}
void unlock(mutex* pm) {
	cout << "unlock" << endl;
}

class Lock {
public:
	Lock(mutex *pm) : mutexPtr(0, unlock) {
		lock(mutexPtr.get());
	}
private:
	shared_ptr<mutex> mutexPtr;
};

class FontHandle {

};

class Font {
public:
	FontHandle& get() { return fh; }

	operator FontHandle() {
		return fh;
	}
private:
	FontHandle fh;
};

int main3() {
	shared_ptr<int> spi(0);

	return EXIT_SUCCESS;
}