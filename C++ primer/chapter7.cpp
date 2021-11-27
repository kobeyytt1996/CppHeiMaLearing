#include <iostream>
using namespace std;
#include "Person.h"

struct Sales_data {
	string isbn() const {

	}

	double avg_price() const;

	Sales_data& combine() {
		return *this;
	}
};

double Sales_data::avg_price() const {
	return 0.0;
}

int main() {


	return EXIT_SUCCESS;
}