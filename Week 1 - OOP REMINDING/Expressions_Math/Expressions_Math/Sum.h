#pragma once
#include <iostream>
#include <vector>
#include "Min.h"
#include "Constant.h"
class Sum : public MathExpression
{
private:
	std::vector<MathExpression*> sum_of_expressions;
public:
	Sum();
	Sum& addExpression(MathExpression* math_expression);
	const double value() const;
	void print() const;
};

