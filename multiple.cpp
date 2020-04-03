#include "multiple.h"

Multiple::Multiple(): lo(0), ro(0){}

Multiple::Multiple(int a, int b) {
	if (b == 0)
		throw "Right operand can't be 0. You can't divide by 0!";
	lo = a;
	ro = b;
}

Multiple::Multiple(const Multiple& obj): lo(obj.lo), ro(obj.ro){}

Multiple::Multiple(Multiple&& obj) noexcept : lo(obj.lo), ro(obj.ro) {
	obj.lo = 0;
	obj.ro = 0;
}

Multiple& Multiple::operator=(const Multiple& obj) {
	if (this == &obj)
		return *this;

	lo = obj.lo;
	ro = obj.ro;
	return *this;
}

Multiple& Multiple::operator= (Multiple && obj) noexcept {
	if (this == &obj) {
		obj.lo = 0;
		obj.ro = 0;
		return *this;
	}

	lo = obj.lo; obj.lo = 0;
	ro = obj.ro; obj.ro = 0;
	return *this;
}

int Multiple::getLO() const{
	return lo;
}

int Multiple::getRO() const {
	return ro;
}

int Multiple::getResult() const
{
	int max = 0;
	if (lo > ro)
		max = lo;
	else max = ro;
	for (int i = max;; ++i)
		if ((i % lo == 0) && (i % ro == 0))
			return i;
}

int Multiple::getResult(int lhs, int rhs) {
	if (rhs == 0)
		throw "Right operand can't be 0. You can't divide by 0!";

	lo = lhs;
	ro = rhs;

	int max = 0;
	if (lo > ro)
		max = lo;
	else max = ro;
	for (int i = max;; ++i)
		if ((i % lo == 0) && (i % ro == 0))
			return i;
}

void Multiple::print(std::ostream& out) const {
	out << "The least common multiple of " << lo << " and " << ro << " is " << getResult() << std::endl << std::endl;
}

void Multiple::print(std::ostream& out, int lhs, int rhs) {
	if (rhs == 0)
		throw "Right operand can't be 0. You can't divide by 0!";

	lo = lhs;
	ro = rhs;
	out << "The least common multiple of " << lhs << " and " << rhs << " is " << getResult(lhs, rhs) << std::endl << std::endl;
}

bool Multiple::equals(const Operator& obj)const {
	//make pointer to the non-const object
	Operator* tmp = const_cast<Operator*>(&obj);

	//try to cast 'tmp' into 'Multiple' object
	Multiple* copy = dynamic_cast<Multiple*>(tmp);

	//if dynamic_cast returned nullptr
	if (!copy)
		return false;

	//equals fields
	if (lo == copy->lo)
		if (ro == copy->ro)
			return true;
	return false;
}