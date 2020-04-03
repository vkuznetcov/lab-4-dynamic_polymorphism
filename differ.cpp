#include "differ.h"

Differ::Differ(): lo(0), ro(0){}

Differ::Differ(int a, int b): lo(a), ro(b){}

Differ::Differ(const Differ& obj): lo(obj.lo), ro(obj.ro){}

Differ::Differ(Differ&& obj) noexcept : lo(obj.lo), ro(obj.ro){
	obj.lo = 0;
	obj.ro = 0;
}

Differ& Differ::operator=(const Differ& obj){
	if (this == &obj)
		return *this;

	lo = obj.lo;
	ro = obj.ro;
	return *this;
}

Differ& Differ::operator=(Differ&& obj) noexcept {
	if (this == &obj) {
		obj.lo = 0;
		obj.ro = 0;
		return *this;
	}

	lo = obj.lo; obj.lo = 0;
	ro = obj.ro; obj.ro = 0;
	return *this;
}

int Differ::getResult() const
{
	return lo - ro;
}

int Differ::getResult(int lhs, int rhs){
	lo = lhs;
	ro = rhs;
	return lhs - rhs;
}

int Differ::getLO() const{
	return lo;
}

int Differ::getRO() const{
	return ro;
}

void Differ::print(std::ostream& out) const{
	out << lo << " - " << ro << " = " << lo - ro << std::endl << std::endl;
}

void Differ::print(std::ostream& out, int lhs, int rhs) {
	lo = lhs;
	ro = rhs;
	out << lhs << " - " << rhs << " = " << lhs - rhs << std::endl << std::endl;
}

bool Differ::equals(const Operator& obj) const {
	//make pointer to the non-const object
	Operator* tmp = const_cast<Operator*>(&obj);

	//try to cast 'tmp' into 'Differ' object
	Differ* copy = dynamic_cast<Differ*>(tmp);

	//if dynamic_cast returned nullptr
	if (!copy)
		return false;

	//equals fields
	if (lo == copy->lo)
		if (ro == copy->ro)
			return true;
	return false;
}


