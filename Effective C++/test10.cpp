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

template<typename Alloc>
void cookieTest(Alloc& alloc, size_t n) {
	typename Alloc::value_type* p1, * p2, * p3;
	p1 = alloc.allocate(n);
	p2 = alloc.allocate(n);
	p3 = alloc.allocate(n);

	cout << p1 << '\t' << p2 << '\t' << p3 << endl;
	alloc.deallocate(p1, sizeof(typename Alloc::value_type));
	alloc.deallocate(p2, sizeof(typename Alloc::value_type));
	alloc.deallocate(p3, sizeof(typename Alloc::value_type));
}

int main() {
	allocator<double> alloc;
	cookieTest(alloc, 1);

	return 1;
}