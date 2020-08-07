#pragma once
#include <iostream>
#include <string>
class Person
{
protected:
	std::string name;
	std::string surname;
	size_t age;
public:
	Person();
	Person(const std::string& _name, const std::string& _surname, size_t _age);
	virtual void print() const = 0;
};

