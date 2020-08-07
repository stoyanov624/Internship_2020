#include "Constant.h"

Constant::Constant() :constant(1) {}

Constant::Constant(const double _constant) : constant(_constant) {}

const double Constant::value() const {
	return this->constant;
}

void Constant::print() const {
	std::cout << this->constant;
}