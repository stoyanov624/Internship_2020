#pragma once
#include <iostream>
#include <cstring>
class Elf
{
private:
	std::string elf_name;
	int elf_age;
	int elf_abillity;
public:
//constructors
	Elf();
	Elf(const std::string& elf_name, const int& elf_age, const int& elf_abillity);
//setters and getters
	void setElfName(const std::string& _elf_name);
	void setElfAge(const int& _elf_age);
	void setElfAbillity(const int& _elf_abillity);
	const std::string& getElfName() const;
	const int& getElfAge() const;
	const int& getElfAbillity() const;
//operators
	friend std::ostream& operator<<(std::ostream& out, const Elf& elf);
//methods
	void printElf() const;
};

