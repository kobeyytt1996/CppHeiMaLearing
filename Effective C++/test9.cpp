#include <unordered_set>
#include <tuple>
#include <string>
#include <iostream>


using std::tuple;
using std::unordered_set;
using std::hash;
using std::string;
using std::cout;
using std::endl;
using std::allocator;
using std::nothrow;

int (*pf)(int x);

class Demo {
	int i1, i2;
	int* i3 = new int(5);
public:
	~Demo() {
		delete i3;
	}
}; 

class Foo {
public:
	static void* operator new(size_t size) {
		Foo* p = static_cast<Foo*>(malloc(size));
		cout << "Foo new" << endl;
		return p;
	}

	static void operator delete(void* pdead, size_t) {
		cout << "Foo delete1" << endl;
		delete pdead;
	}

	static void operator delete(void* pdead) {
		cout << "Foo delete2" << endl;
		delete pdead;
	}
};

class Screen {
public:
	static void* operator new(size_t size) {
		Screen* p;
		if (!freeStore) {
			freeStore = p = reinterpret_cast<Screen*>(new char[size * screenChunk]);
			while (p != &freeStore[screenChunk-1]) {
				p->next = p + 1;
				++p;
			}
			p->next = nullptr;
		}
		p = freeStore;
		freeStore = freeStore->next;
		return p;
	}

	static void operator delete(void* p) {
		static_cast<Screen*>(p)->next = freeStore;
		freeStore = static_cast<Screen*>(p);
	}
private:
	Screen* next;
	static Screen* freeStore;
	static const int screenChunk = 24;
private:
	int i = 0;
};

Screen* Screen::freeStore = nullptr;

class MyAlloc {
private:
	struct obj {
		obj* next;
	};
public:
	void* allocate(size_t size) {
		obj* p;
		if (!freeStore) {
			freeStore = p = static_cast<obj*>(malloc(size * CHUNK));
			for (int i = 0; i < (CHUNK - 1); ++i) {
				p->next = reinterpret_cast<obj*>(reinterpret_cast<char*>(p) + size);
				p = p->next;
			}
			p->next = nullptr;
		}
		p = freeStore;
		freeStore = p->next;
		return p;
	}
	void deallocate(void* p, size_t) {
		static_cast<obj*>(p)->next = freeStore;
		freeStore = static_cast<obj*>(p);
	}
private:
	obj* freeStore = nullptr;
	const int CHUNK = 5;
};

class Goo {
	static MyAlloc myAlloc;

public:
	static void* operator new(size_t size) {
		if (size != sizeof(Goo)) {
			return ::operator new(size);
		}
		return myAlloc.allocate(size);
	}

	static void operator delete(void* p, size_t size) {
		if (size != sizeof(Goo)) {
			return ::operator delete(p);
		}
		myAlloc.deallocate(p, size);
	}
};

MyAlloc Goo::myAlloc;

class NoNew {
public:
	static void* operator new(size_t size) = delete;
};

int main9() {
	unordered_set<int>::iterator::iterator_category;
	hash<float>()(3.2F);
	cout << sizeof(tuple<int, double>) << endl;
	void* p1 = malloc(512);
	free(p1);

	void* p2 = ::operator new(512);
	::operator delete(p2);

	int* p3 = allocator<int>().allocate(3 );
	allocator<int>().deallocate(p3, 3);

	int* p4 = new int[20];
	delete p4;

	Demo* p5 = new Demo[20];
	delete[] p5;

	Foo* pF1 = new Foo;
	delete pF1;

	Screen* pS = new Screen;
	delete pS;

	Goo* pG = new Goo;
	delete pG;

	int* pI3 = new (nothrow) int;

	

	return 1;
}

