#pragma once
#include <iostream>
#include "MathExpression.h"
class Constant : public MathExpression
{
private:
	const double constant;
public:
	Constant();
	Constant(const double _constant);
	const double value() const;
	void print() const;
};

