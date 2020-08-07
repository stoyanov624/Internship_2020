#include <iostream>
#include "Sum.h"
int main()
{
	MathExpression* m_const1 = new Constant(100);
	MathExpression* m_const2 = new Constant(5);
	MathExpression* m_exp1 = new Min(m_const1, m_const2);
	
	Sum s1;
	Sum s2;

	s2.addExpression(m_exp1).addExpression(m_const2).addExpression(&s1);

	s2.print();
	std::cout << std::endl << s2.value();

	delete m_const1;
	delete m_const2;
	delete m_exp1;
}
