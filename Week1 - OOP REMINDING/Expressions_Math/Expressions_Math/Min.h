#pragma once
#include <iostream>
#include <algorithm>
#include "MathExpression.h"
class Min : public MathExpression
{
private:
	MathExpression* constant1;
	MathExpression* constant2;
public:
	Min();
	Min(MathExpression* _constant1, MathExpression* _constant2);
	const double value() const;
	void print() const;
};

