#include "Sum.h"

Sum::Sum() :sum_of_expressions() {}

Sum& Sum::addExpression(MathExpression* math_expression) 
{
	if (sum_of_expressions.size() >= 10) 
	{
		std::cout << "Can't add more than 10 expression!" << std::endl;
		return *this;
	}
	
	sum_of_expressions.push_back(math_expression);
	return *this;
}

const double Sum::value() const 
{
	double sum = 0;

	for (size_t i = 0, SIZE = sum_of_expressions.size(); i < SIZE; i++)
	{
		sum += sum_of_expressions[i]->value();
	}

	return sum;
}

void Sum::print() const 
{
	std::cout << "sum (";
	for (size_t i = 0, SIZE = sum_of_expressions.size(); i < SIZE; i++)
	{
		sum_of_expressions[i]->print();
		if (i < SIZE - 1) {
			std::cout << ",";
		}
	}
	std::cout << ")";
}