#include "Elf.h"

Elf::Elf() : elf_name(), elf_age(1), elf_abillity(1) {}

Elf::Elf(const std::string& _elf_name, const int& _elf_age, const int& _elf_abillity)
{
	this->setElfName(_elf_name);
	this->setElfAge(_elf_age);
	this->setElfAbillity(_elf_abillity);
}

void Elf::setElfName(const std::string& _elf_name) 
{
	this->elf_name = _elf_name;
}

void Elf::setElfAge(const int& _elf_age) 
{
	if (_elf_age <= 0 || _elf_age > 300)
	{
		this->elf_age = 1;
	}
	else
	{
		this->elf_age = _elf_age;
	}
}

void Elf::setElfAbillity(const int& _elf_abillity)
{
	if (_elf_abillity <= 0 || _elf_abillity > 15)
	{
		this->elf_abillity = 1;
	}
	else
	{
		this->elf_abillity = _elf_abillity;
	}
}

const std::string& Elf::getElfName() const 
{
	return this->elf_name;
}

const int& Elf::getElfAge() const 
{
	return this->elf_age;
}

const int& Elf::getElfAbillity() const 
{
	return this->elf_abillity;
}

std::ostream& operator<<(std::ostream& out, const Elf& elf)
{
	out << "Elf name: " << elf.elf_name << std::endl;
	out << "Elf age: " << elf.elf_age << std::endl;
	out << "Elf abillity: " << elf.elf_abillity << std::endl;

	return out;
}

void Elf::printElf() const 
{
	std::cout << "Elf name: " << this->elf_name << std::endl;
	std::cout << "Elf age: " << this->elf_age << std::endl;
	std::cout << "Elf abillity: " << this->elf_abillity << std::endl;
}