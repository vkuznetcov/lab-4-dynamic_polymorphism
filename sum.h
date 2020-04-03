#pragma once
#include "operator.h"
class Sum : public Operator {
private:
	int lo;
	int ro;
public:
	//standart c-tor
	Sum();

	//c-tor with parameters
	Sum(int a, int b);

	//copy c-tor
	Sum(const Sum& obj);

	//move c-tor
	Sum(Sum&& obj) noexcept;

	//copy assign
	Sum& operator=(const Sum& obj);

	//move assign
	Sum& operator=(Sum&& obj) noexcept;

	//calculate result with object's parameters
	int getResult() const override;

	//calculate result using user parameters
	int getResult(int lhs, int rhs) override;

	int getLO() const;

	int getRO() const;

	//print calculation using object's parameters
	void print(std::ostream& out) const override;

	//print calculation using user's parameters and changings object's
	void print(std::ostream& out, int lhs, int rhs) override;

	bool equals(const Operator& opr) const override;
};