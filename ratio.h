#pragma once
#include "operator.h"
class Ratio :public Operator {
private:
	int lo;
	int ro;
public:
	//default c-tor
	Ratio();

	//c-tor with parameters
	Ratio(int a, int b);

	//copy c-tor
	Ratio(const Ratio& obj);

	//move c-tor
	Ratio(Ratio&& obj) noexcept;

	//copy assignment
	Ratio& operator=(const Ratio& obj);

	//move assignment
	Ratio& operator=(Ratio&& obj) noexcept;

	//calculate result with object parameters
	int getResult() const override;

	//calculate result with user parameters
	int getResult(int lhs, int rhs) override;

	int getLO() const;

	int getRO() const;

	//print calculation using object's parameters
	void print(std::ostream& out) const override;

	//print calculation using user's parameters
	void print(std::ostream& out, int lhs, int rhs) override;

	bool equals(const Operator& obj) const override;
};