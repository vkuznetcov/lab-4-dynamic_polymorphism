#pragma once
#include "operator.h"

class Multi : public Operator {
private:
	int lo;
	int ro;
public:
	//default c-tor without parameters
	Multi();

	//c-tor with parameters
	Multi(int a, int b);

	//copy c-tor
	Multi(const Multi& obj);

	//move c-tor
	Multi(Multi&& obj) noexcept;

	//copy assignment
	Multi& operator=(const Multi& obj);

	//move assignment
	Multi& operator=(Multi&& obj) noexcept;

	int getLO() const;

	int getRO() const;

	//calculate result using object parameters
	int getResult() const override;

	//calculate result using user parameters
	int getResult(int lhs, int rhs) override;

	//print result as a string with object's parameters
	void print(std::ostream& out) const override;

	//print result as a string using user's parameters
	void print(std::ostream& out, int lhs, int rhs) override;

	bool equals(const Operator& obj) const;

};