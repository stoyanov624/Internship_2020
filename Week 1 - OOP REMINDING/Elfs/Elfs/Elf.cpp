#include "Elf.h"

Elf::Elf() : elf_name(), elf_age(1), elf_abillity(1) {}

Elf::Elf(const std::string& _elf_name, int _elf_age, int _elf_abillity)
{
	this->setElfName(_elf_name);
	this->setElfAge(_elf_age);
	this->setElfAbillity(_elf_abillity);
}

void Elf::setElfName(const std::string& _elf_name) 
{
	this->elf_name = _elf_name;
}

void Elf::setElfAge(int _elf_age) 
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

void Elf::setElfAbillity(int _elf_abillity)
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

int Elf::getElfAge() const 
{
	return this->elf_age;
}

int Elf::getElfAbillity() const 
{
	return this->elf_abillity;
}

bool Elf::operator==(const Elf& other_elf) const
{
	return (this->elf_abillity == other_elf.elf_abillity && this->elf_name == other_elf.elf_name && this->elf_age == other_elf.elf_age);
}

bool Elf::operator!=(const Elf& other_elf) const
{
	return !(*this == other_elf);
}

std::ostream& operator<<(std::ostream& out, const Elf& elf)
{
	out << "Elf name: " << elf.elf_name << std::endl;
	out << "Elf age: " << elf.elf_age << std::endl;
	out << "Elf abillity: " << elf.elf_abillity << std::endl;

	return out;
}

