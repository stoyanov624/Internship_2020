#pragma once
#include <iostream>
class MathExpression
{
public:
	virtual const double value() const = 0;
	virtual void print() const = 0;
};

