#pragma once
#include <iostream>
#include <string>
#include "Person.h"

class Employee : public Person
{
private:
	std::string firm_status;
	double salary;
public:
	Employee();
	Employee(const std::string& _name, const std::string& _surname, size_t _age, const std::string _firm_status, double _salary);
	void print() const;
};

