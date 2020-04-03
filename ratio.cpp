#include "ratio.h"

Ratio::Ratio() : lo(0), ro(0) {}

Ratio::Ratio(int a, int b) {
	if (b == 0)
		throw "Right operand can't be 0. You can't divide by 0!";

	lo = a;
	ro = b;
}

Ratio::Ratio(const Ratio& obj) : lo(obj.lo), ro(obj.ro) {}

Ratio::Ratio(Ratio&& obj) noexcept : lo(obj.lo), ro(obj.ro) {
	obj.lo = 0;
	obj.ro = 0;
}

Ratio& Ratio::operator=(const Ratio& obj) {
	if (this == &obj)
		return *this;

	lo = obj.lo;
	ro = obj.ro;
	return *this;
}

Ratio& Ratio::operator=(Ratio&& obj) noexcept {
	if (this == &obj) {
		obj.lo = 0;
		obj.ro = 0;
		return *this;
	}

	lo = obj.lo; obj.lo = 0;
	ro = obj.ro; obj.ro = 0;
	return *this;
}

int Ratio::getResult() const{
	return lo / ro;
}

int Ratio::getResult(int lhs, int rhs){
	if (rhs == 0)
		throw "Right operand can't be 0. You can't divide by 0!";

	lo = lhs;
	ro = rhs;
	return lhs / rhs;
}

int Ratio::getLO() const{
	return lo;
}

int Ratio::getRO() const{
	return ro;
}

void Ratio::print(std::ostream& out) const {
	out << lo << " / " << ro << " = " << lo / ro << std::endl << std::endl;
}

void Ratio::print(std::ostream& out, int lhs, int rhs) {
	if (rhs == 0)
		throw "Right operand can't be 0. You can't divide by 0!";

	out << lhs << " / " << rhs << "=" << lhs / rhs << std::endl << std::endl;
	lo = lhs;
	ro = rhs;
}

bool Ratio::equals(const Operator& obj) const {
	//make pointer to the non-const object
	Operator* tmp = const_cast<Operator*>(&obj);

	//try to cast 'tmp' into 'Ratio' object
	Ratio* copy = dynamic_cast<Ratio*>(tmp);

	//if dynamic_cast returned nullptr
	if (!copy)
		return false;

	//equals fields
	if (lo == copy->lo)
		if (ro == copy->ro)
			return true;
	return false;
}