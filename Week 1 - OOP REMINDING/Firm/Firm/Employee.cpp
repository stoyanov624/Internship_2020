#include "Employee.h"

Employee::Employee():firm_status(),salary(0)
{
	this->name = "";
	this->surname = "";
	this->age = 18;
}

Employee::Employee(const std::string& _name, const std::string& _surname, size_t _age, const std::string _firm_status, double _salary) :firm_status(_firm_status), salary(_salary)
{
	this->name = _name;
	this->surname = _surname;
	this->age = _age;
}

void Employee::print() const 
{
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Surname: " << this->surname << std::endl;
	std::cout << "Age: " << this->age << std::endl;
	std::cout << "Firm status: " << this->firm_status << std::endl;
	std::cout << "Salary: " << this->salary << std::endl;
}
