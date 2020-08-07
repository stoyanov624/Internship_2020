#include <iostream>
#include "Person.h"
#include "Employee.h"
#include "Company.h"
int main()
{
	Employee* p1 = new Employee("John","Johnson",23,"CEO",6666);
	Employee* p2 = new Employee("Jack","Jackson",20,"High-tier Slave",10);
	Employee* p3 = new Employee("Tom","Thomson",18,"Slave",0);
	Company c1("Sony");

	c1.hire_employee(p1);
	c1.hire_employee(p2);
	c1.hire_employee(p3);
	c1.print_employees();
}
