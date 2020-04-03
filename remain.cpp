#include "remain.h"

Remain::Remain(): lo(0), ro(0){}

Remain::Remain(int a, int b): lo(a), ro(b){}

Remain::Remain(const Remain& obj): lo(obj.lo), ro(obj.ro){}

Remain::Remain(Remain&& obj) noexcept : lo(obj.lo), ro(obj.ro){
	obj.lo = 0;
	obj.ro = 0;
}

Remain& Remain::operator=(const Remain& obj){
	if (this == &obj)
		return *this;

	lo = obj.lo;
	ro = obj.ro;
	return *this;
}

Remain& Remain::operator=(Remain&& obj) noexcept {
	if (this == &obj) {
		obj.lo = 0;
		obj.ro = 0;
		return *this;
	}

	lo = obj.lo; obj.lo = 0;
	ro = obj.ro; obj.ro = 0;
	return *this;
}

int Remain::getLO(){
	return lo;
}

int Remain::getRO(){
	return ro;
}

int Remain::getResult() const{
	return lo % ro;
}

int Remain::getResult(int lhs, int rhs){
	lo = lhs;
	ro = rhs;
	return lhs % rhs;
}

void Remain::print(std::ostream& out) const{
	out << "reminder of dividing " << lo << " by " << ro << " is " << lo % ro << "    (" << lo << " % " << ro << " = " << lo % ro << ")" << std::endl << std::endl;
}

void Remain::print(std::ostream& out, int lhs, int rhs){
	lo = lhs;
	ro = rhs;
	out << "reminder of dividing " << lhs << " by " << rhs << " is " << lhs % rhs << "    (" << lhs << " % " << rhs << " = " << lhs % rhs << ")" << std::endl << std::endl;
}

bool Remain::equals(const Operator& obj) const {
	//make pointer to the non-const object
	Operator* tmp = const_cast<Operator*>(&obj);

	//try to cast 'tmp' into 'Remain' object
	Remain* copy = dynamic_cast<Remain*>(tmp);

	//if dynamic_cast returned nullptr
	if (!copy)
		return false;

	//equals fields
	if (lo == copy->lo)
		if (ro == copy->ro)
			return true;
	return false;
}
