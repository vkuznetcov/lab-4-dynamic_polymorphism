#pragma once
#include <iostream>

class Operator {
protected:
	//standart c-tor for copying on base level
	Operator() = default;

	//allow to copy derivative classes
	Operator(const Operator& obj) = default;

	//allow to copy derivative classes by assignment
	Operator& operator=(const Operator& obj) = default;
public:
	//default vitrual d-tor for deleting actual objects
	virtual ~Operator() = default;

	//calculate result with object parameters
	virtual int getResult() const = 0;

	//calcuate result with user parameters
	virtual int getResult(int lhs, int rhs) = 0;

	//print operator and result as a string using object parameters
	virtual void print(std::ostream& out) const = 0;

	//print operator and result as a string using user parameters and changing object's parameters
	virtual void print(std::ostream& out, int lhs, int rhs) = 0;

	//equals two functions
	virtual bool equals(const Operator& opr) const = 0;

};