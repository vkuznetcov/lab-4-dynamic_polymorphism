#pragma once
#include "operator.h"

class bigDivider : public Operator {
private:
	int lo;
	int ro;
public:
	//default c-tor
	bigDivider();

	//c-tor with parameters
	bigDivider(int a, int b);

	//copy c-tor
	bigDivider(const bigDivider& obj);

	//move c-tor
	bigDivider(bigDivider&& obj) noexcept;

	//copy assignment
	bigDivider& operator=(const bigDivider& obj);

	//move assignment
	bigDivider& operator=(bigDivider&& obj) noexcept;

	int getLO() const;

	int getRO() const;

	//calculate result using object's parameters
	int getResult() const override;

	//calculate result using user's parameters and changing object's
	int getResult(int lhs, int rhs) override;

	//print calculation as a string with object's parameters
	void print(std::ostream& out) const override;

	//print calculation as a string with user's parameters and changing object's
	void print(std::ostream& out, int lhs, int rhs) override;

	bool equals(const Operator& obj) const override;
};