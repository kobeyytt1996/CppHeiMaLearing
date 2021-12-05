#include <iostream>
#include <string>
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

int main() {
	Employee e1("Curry");
	Employee e2(e1);
	e1.empPrint();
	e2.empPrint();

	return EXIT_SUCCESS;
}