#pragma once
#include "operator.h"

class Multiple : public Operator {
private:
	int lo;
	int ro;
public:
	//default c-tor
	Multiple();

	//c-tor with parameters
	Multiple(int a, int b);

	//copy c-tor
	Multiple(const Multiple& obj);

	//move c-tor
	Multiple(Multiple&& obj) noexcept;

	//copy assignment
	Multiple& operator=(const Multiple& obj);

	//move assignment
	Multiple& operator=(Multiple&& obj) noexcept;

	int getLO() const;

	int getRO() const;

	//calculate result using object's parameters
	int getResult() const override;

	//calculate result using user's parameters
	int getResult(int lhs, int rhs) override;

	//print calculation as a string with object's parameters
	void print(std::ostream& out) const override;

	//print calculation as a string with user's parameters
	void print(std::ostream& out, int lhs, int rhs) override;

	bool equals(const Operator& obj) const override;
};