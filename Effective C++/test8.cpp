#include <iterator>
#include <string>
#include <boost/smart_ptr.hpp>
#include <tuple>
#include <iostream>
#include <iterator>
#include "Rational.hpp"
#include <new>
using std::ostream;
using std::tuple;
using std::string;
using std::iterator_traits;
using boost::scoped_array;
using std::cout;
using std::endl;
using std::make_tuple;
using std::get;
using std::random_access_iterator_tag;
using std::bidirectional_iterator_tag;
using std::set_new_handler;
using std::new_handler;
using std::cerr;

void my_new_handler() {
	cerr << "not enough" << endl;
	abort();
}

class NewHandlerHolder {
public:
	explicit NewHandlerHolder(const new_handler& handler) : globalHandler(handler) {}

	~NewHandlerHolder() noexcept {
		set_new_handler(globalHandler);
	}
private:
	new_handler globalHandler;
};

template<typename T>
class NewHandlerSupport {
public:
	static new_handler set_new_handler(new_handler handler);

private:
	new_handler currentHandler;
};

int main08() {
	set_new_handler(my_new_handler);
	//int* pI = new int[500000000];
	return 1;
	
}