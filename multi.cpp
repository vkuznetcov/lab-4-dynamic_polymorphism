#include "multi.h"

Multi::Multi(): lo(0), ro(0){}

Multi::Multi(int a, int b): lo(a), ro(b){}

Multi::Multi(const Multi& obj): lo(obj.lo), ro(obj.ro){}

Multi::Multi(Multi&& obj) noexcept : lo(obj.lo), ro(obj.ro) {
	obj.lo = 0;
	obj.ro = 0;
}

Multi& Multi::operator=(const Multi& obj){
	if (this == &obj)
		return *this;

	lo = obj.lo;
	ro = obj.ro;
	return *this;
}

Multi& Multi::operator=(Multi&& obj) noexcept {
	if (this == &obj) {
		obj.lo = 0;
		obj.ro = 0;
		return *this;
	}

	lo = obj.lo; obj.lo = 0;
	ro = obj.ro; obj.ro = 0;
	return *this;
}

int Multi::getLO() const{
	return lo;
}

int Multi::getRO() const{
	return ro;
}

int Multi::getResult() const{
	return lo * ro;
}

int Multi::getResult(int lhs, int rhs){
	lo = lhs;
	ro = rhs;
	return lhs * rhs;
}

void Multi::print(std::ostream& out) const{
	out << lo << " * " << ro << " = " << lo * ro << std::endl << std::endl;
}

void Multi::print(std::ostream& out, int lhs, int rhs){
	out << lhs << " * " << rhs << " = " << lhs * rhs << std::endl << std::endl;
	lo = lhs;
	ro = rhs;
}

bool Multi::equals(const Operator& obj) const {
	//make pointer to the non-const object
	Operator* tmp = const_cast<Operator*>(&obj);

	//try to cast 'tmp' into 'Multi' object
	Multi* copy = dynamic_cast<Multi*>(tmp);

	//if dynamic_cast returned nullptr
	if (!copy)
		return false;

	//equals fields
	if (lo == copy->lo)
		if (ro == copy->ro)
			return true;
	return false;
}
