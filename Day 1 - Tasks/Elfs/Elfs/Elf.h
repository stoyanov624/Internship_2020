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
	Elf(const std::string& elf_name, int elf_age, int elf_abillity);
//setters and getters
	void setElfName(const std::string& _elf_name);
	void setElfAge(int _elf_age);
	void setElfAbillity(int _elf_abillity);
	const std::string& getElfName() const;
	int getElfAge() const;
	int getElfAbillity() const;
//operators
	bool operator==(const Elf& other_elf) const;
	bool operator!=(const Elf& other_elf) const;
	friend std::ostream& operator<<(std::ostream& out, const Elf& elf);
};

