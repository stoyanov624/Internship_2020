#include "Company.h"

Company::Company() : company_name(),employees() {}

Company::Company(const std::string& _company_name) : company_name(_company_name),employees() {}

Company& Company::hire_employee(Employee* employee) 
{
	this->employees.push_back(employee);
	return *this;
}

void Company::print_employees() const 
{
	std::cout << "Firm name: " << this->company_name << std::endl;
	std::cout << "Employees: " << std::endl;
	for (size_t i = 0,SIZE = this->employees.size(); i < SIZE; i++)
	{
		this->employees[i]->print();
	}
}
