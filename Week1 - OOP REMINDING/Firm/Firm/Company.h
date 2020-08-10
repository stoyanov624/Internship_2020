#pragma once
#include <vector>
#include <string>
#include "Employee.h"
class Company
{
private:
	std::string company_name;
	std::vector<Employee> employees;
public:
	Company();
	Company(const std::string& _company_name);
	Company& hire_employee(const Employee& employee);
	void print_employees() const;
};

