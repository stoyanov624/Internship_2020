#include "Person.h"
Person::Person(): name(),surname(),age(18) {}

Person::Person(const std::string& _name, const std::string& _surname, size_t _age) : name(_name), surname(_surname), age(_age) {}