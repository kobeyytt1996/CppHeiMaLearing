#include <iostream>
#include <string>
#include "Message.h"
#include <algorithm>
#include <vector>
using namespace std;

class HasPtr {
public:
	friend void swap(HasPtr& hp1, HasPtr& hp2);
	// ×¢ÊÍµÄÊÇvalue_likeµÄ
	/*HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}

	HasPtr(const HasPtr &hasPtr) : ps(new string(*(hasPtr.ps))), i(hasPtr.i) {}

	HasPtr& operator=(const HasPtr& hasPtr) {
		auto newP = new string(*(hasPtr.ps));
		delete ps;
		ps = nullptr;

		ps = newP;
		i = hasPtr.i;

		return *this;
	}

	~HasPtr() {
		delete ps;
	}*/

	HasPtr(const string &s) : ps(new string(s)), i(0), use(new size_t(1)) {}
	HasPtr(const HasPtr& hp) : ps(hp.ps), i(hp.i), use(hp.use) {
		++(*use);
	}
	HasPtr(HasPtr&& hp) noexcept : ps(hp.ps), i(hp.i) {
		hp.ps = nullptr;
	}

	HasPtr& operator=(const HasPtr& hp);
	~HasPtr();

private:
	string* ps;
	int i;
	size_t* use;
};

void swap(HasPtr& hp1, HasPtr& hp2) {
	swap(hp1.ps, hp2.ps);
	swap(hp1.i, hp2.i);

}

HasPtr& HasPtr::operator=(const HasPtr& hp) {
	++(*(hp.use));
	--(*use);
	if (!*use) {
		delete ps;
		delete use;
	}
	i = hp.i;
	ps = hp.ps;
	use = hp.use;
	return *this;
}

HasPtr::~HasPtr() {
	--(*use);
	if (!*use) {
		delete ps;
		ps = nullptr;
		delete use;
	}
}

struct NoCopy {
	NoCopy(const NoCopy&) = delete;
	NoCopy& operator=(const NoCopy&) = delete;
};

class Employee {
public:
	Employee(const string& s = string()) : name(s), ID(uniqueId) {
		++uniqueId;
	}

	Employee(const Employee& emp) : name(emp.name), ID(uniqueId) {
		++uniqueId;
	}

	Employee& operator=(const Employee& emp) {
		name = emp.name;
		ID = uniqueId;
		++uniqueId;
		return *this;
	}

	void empPrint() {
		cout << name << " " << ID << endl;
	}
private:
	int ID;
	string name;
	static int uniqueId;
};

int Employee::uniqueId = 0;

class StrVec {
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec& sv) : StrVec() {
		auto pairPointer = alloc_n_copy(sv.begin(), sv.end());
		elements = pairPointer.first;
		first_free = pairPointer.second;
		cap = first_free;
	}

	StrVec(StrVec&& sv) noexcept : elements(sv.elements) {
		sv.elements = nullptr;
	}
	StrVec(const initializer_list<string>& il) : StrVec() {
		auto pairPointer = alloc_n_copy(il.begin(), il.end());
		elements = pairPointer.first;
		first_free = pairPointer.second;
		cap = first_free;
	}
	StrVec& operator=(const StrVec& sv) & {
		auto data = alloc_n_copy(sv.begin(), sv.end());
		free();
		first_free = cap = data.second;
		elements = data.first;
	}

	StrVec& operator=(StrVec&& sv) noexcept {
		if (&sv != this) {
			free();
			elements = sv.elements;
			sv.elements = nullptr;
		}
		return *this;
	}
	~StrVec() { free(); }
	void push_back(const string& s) {
		chk_n_alloc();
		alloc.construct(first_free++, s);
	}
	size_t size() const { return first_free - elements; }
	size_t capacity() const {return cap - elements;}
	string* begin() const { return elements; }
	string* end() const { return first_free; }

private:
	static allocator<string> alloc;
	void free() {
		if (elements) {
			for_each(elements, first_free, [](string& s) {alloc.destroy(&s); });
			alloc.deallocate(elements, cap - elements);
		}
	}
	void reallocate() {
		auto newSize = (size() ? 2 * size() : 1);
		auto newData = alloc.allocate(newSize);

		auto dest = newData;
		auto ele = elements;
		while (ele < first_free) {
			alloc.construct(dest++, std::move(*(ele++)));
		}
		free();
		elements = newData;
		first_free = dest;
		cap = elements + newSize;
	}
	void chk_n_alloc() {
		if (size() == capacity()) {
			reallocate();
		}
	}
	pair<string*, string*> alloc_n_copy(const string* b, const string* e) {
		auto data = alloc.allocate(e - b);
		return { data, uninitialized_copy(make_move_iterator(b), make_move_iterator(e), data) };
	}
	string* elements;
	string* first_free;
	string* cap;
};

allocator<string> StrVec::alloc;

int main13() {
	Employee e1("Curry");
	Employee e2(e1);
	e1.empPrint();
	e2.empPrint();

	Message m("aa");
	
	StrVec sv = { "aa"};
	cout << *sv.begin() << endl;

	const int& i = 2.0;
	int&& ri = 20;

	int&& rr1 = 50;
	int&& rr2 = std::move(rr1);

	cout << rr1 << endl;

	string&& srr = "aa";
	srr = "cc";
	string&& srr2 = std::move(srr);

	vector<string> vs1;
	vs1.push_back(std::move(srr2));
	"ss" + string("aa");

	return EXIT_SUCCESS;
}