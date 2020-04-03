#include "big_divider.h"

bigDivider::bigDivider(): lo(0), ro(0){}

bigDivider::bigDivider(int a, int b): lo(a), ro(b){}

bigDivider::bigDivider(const bigDivider& obj): lo(obj.lo), ro(obj.ro){}

bigDivider::bigDivider(bigDivider&& obj) noexcept : lo(obj.lo), ro(obj.ro){
	obj.lo = 0;
	obj.ro = 0;
}

bigDivider& bigDivider::operator=(const bigDivider& obj){
	if (this == &obj)
		return *this;

	lo = obj.lo;
	ro = obj.ro;
	return *this;
}

bigDivider& bigDivider::operator=(bigDivider&& obj) noexcept {
	if (this == &obj) {
		obj.lo = 0;
		obj.ro = 0;
		return *this;
	}

	lo = obj.lo; obj.lo = 0;
	ro = obj.ro; obj.ro = 0;
	return *this;
}

int bigDivider::getLO() const
{
	return lo;
}

int bigDivider::getRO() const
{
	return ro;
}

int bigDivider::getResult() const{
	int max = 0;
	int min = 0;
	if (lo > ro) {
		max = lo;
		min = ro;
	}
	else {
		max = ro;
		min = lo;
	}

	int tmp = 0;

	for (int i = 1; i < max; ++i) {
		if (max % min == 0)
			return min;
		else {
			tmp = min;
			min = max % min;
			max = tmp;
		}
	}
}

int bigDivider::getResult(int lhs, int rhs) {
	lo = lhs;
	ro = rhs;

	int max = 0;
	int min = 0;
	if (lhs > rhs) {
		max = lhs;
		min = rhs;
	}
	else {
		max = rhs;
		min = lhs;
	}

	int tmp = 0;

	for (int i = 1; i < max; ++i) {
		if (max % min == 0)
			return min;
		else {
			tmp = min;
			min = max % min;
			max = tmp;
		}
	}
}

void bigDivider::print(std::ostream& out) const {
	out << "The biggest divider of " << lo << " and " << ro << " is " << getResult() << std::endl << std::endl;
}

void bigDivider::print(std::ostream& out, int lhs, int rhs) {
	out << "The biggest divider of " << lhs << " and " << rhs << " is " << getResult(lhs, rhs) << std::endl << std::endl;
	lo = lhs;
	ro = rhs;
}

bool bigDivider::equals(const Operator& obj) const{
	//make pointer to the non-const object
	Operator* tmp = const_cast<Operator*>(&obj);

	//try to cast 'tmp' into 'bigDivider' object
	bigDivider* copy = dynamic_cast<bigDivider*>(tmp);

	//if dynamic_cast returned nullptr
	if (!copy)
		return false;

	//equals fields
	if (lo == copy->lo)
		if (ro == copy->ro)
			return true;
	return false;
}
