#pragma once
class Base {
public:
	virtual bool equal(const Base& b) const;
};

class Derived : public Base {
public:
	bool equal(const Base& b) const override;
};

bool equal(const Base& b1, const Base& b2);
