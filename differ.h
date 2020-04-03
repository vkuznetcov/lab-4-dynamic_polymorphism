#pragma once
#include "operator.h"
class Differ :public Operator {
private:
	int lo;
	int ro;
public:
	//default c-tor
	Differ();

	//c-tor with parameters
	Differ(int a, int b);

	//copy c-tor
	Differ(const Differ& obj);

	//move c-tor
	Differ(Differ&& obj) noexcept;

	//copy assignment
	Differ& operator=(const Differ& obj);

	//move assignment
	Differ& operator=(Differ&& obj) noexcept;

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