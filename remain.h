#pragma once
#include "operator.h"

class Remain : public Operator {
private:
	int lo;
	int ro;
public:
	//defaul c-tor
	Remain();

	//c-tor with parameters
	Remain(int a, int b);

	//copy c-tor
	Remain(const Remain& obj);

	//move c-tor
	Remain(Remain&& obj) noexcept;

	//copy assignment
	Remain& operator=(const Remain& obj);

	//move assignment
	Remain& operator=(Remain&& obj) noexcept;

	int getLO();

	int getRO();

	//calculate result with object's parameters
	int getResult() const override;

	//calculate result with user's parameters and change object's
	int getResult(int lhs, int rhs) override;

	//print calculation as a string with object's parameters
	void print(std::ostream& out) const override;

	//print calulation as a string with user's parameters
	void print(std::ostream& out, int lhs, int rhs) override;

	bool equals(const Operator& obj) const override;
};