#pragma once
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class Rational {
public:
	Rational(const T& deno = 0, const T& nume = 0) : denomitor(deno), numeritor(nume) {}

	const T deno() const {
		return denomitor;
	}

	const T nume() const {
		return numeritor;
	}
private:
	T denomitor;
	T numeritor;

	friend const Rational operator*(const Rational& lR, const Rational& rR) {
		return doMultiply(lR, rR);
	}
};

template<typename T>
const Rational<T> operator*(const Rational<T>& lR, const Rational<T>& rR) {
	return Rational<T>(lR.deno() * rR.deno(), lR.nume() * rR.nume());
}

template<typename T>
Rational<T> doMultiply(const Rational<T>& lR, const Rational<T>& rR) {
	cout << "doMul" << endl;
	return Rational<T>(lR.deno() * rR.deno(), lR.nume() * rR.nume());
}
