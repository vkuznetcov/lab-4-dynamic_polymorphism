#include "sum.h"

Sum::Sum(): lo(0), ro(0){}

Sum::Sum(int a, int b): lo(a), ro(b){}

Sum::Sum(const Sum& obj): lo(obj.lo), ro(obj.ro){}

Sum::Sum(Sum&& obj) noexcept : lo(obj.lo), ro(obj.ro){
	obj.lo = 0;
	obj.ro = 0;
}

Sum& Sum::operator=(const Sum& obj){
	if (this == &obj)
		return *this;

	lo = obj.lo;
	ro = obj.ro;

	return *this;
}

Sum& Sum::operator=(Sum&& obj) noexcept{
	if (this == &obj) {
		obj.lo = 0;
		obj.ro = 0;
		return *this;
	}

	lo = obj.lo; obj.lo = 0;
	ro = obj.ro; obj.ro = 0;
	return *this;
}

int Sum::getResult() const{
	return lo + ro;
}

int Sum::getResult(int lhs, int rhs){
	lo = lhs;
	ro = rhs;
	return lhs + rhs;
}

int Sum::getLO() const{
	return lo;
}

int Sum::getRO() const{
	return ro;
}

void Sum::print(std::ostream& out) const{
	out << lo << " + " << ro << " = " << lo + ro << std::endl << std::endl;
}

void Sum::print(std::ostream& out, int lhs, int rhs){
	out << lhs << " + " << rhs << " = " << lhs + rhs << std::endl << std::endl;
	lo = lhs;
	ro = rhs;
}

bool Sum::equals(const Operator& opr) const {
	//make pointer to the non-const object
	Operator* tmp = const_cast<Operator*>(&opr);

	//try to cast 'tmp' into 'Sum' object
	Sum* copy = dynamic_cast<Sum*>(tmp);

	//if dynamic_cast returned nullptr
	if (!copy)
		return false;

	//equals fields
	if (lo == copy->lo)
		if (ro == copy->ro)
			return true;
	return false;
}
