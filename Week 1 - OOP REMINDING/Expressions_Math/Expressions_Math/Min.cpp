#include "Min.h"

Min::Min() :constant1(), constant2(){}

Min::Min(MathExpression* _constant1, MathExpression* _constant2) : constant1(_constant1), constant2(_constant2) {}

const double Min::value() const {
	return std::min(this->constant1->value(), this->constant2->value());
}

void Min::print() const {
	std::cout << "min (" << this->constant1->value() << "," << this->constant2->value() << ")";
}