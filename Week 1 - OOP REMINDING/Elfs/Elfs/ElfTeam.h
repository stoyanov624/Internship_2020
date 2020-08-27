#pragma once
#include <iostream>
#include "Elf.h"
class ElfTeam
{
private:
	char team_name[30];
	Elf elf_team[50];
	size_t team_size;

	void rename(const char* _team_name);

public:
//constructors
	ElfTeam();
	ElfTeam(const char* _team_name);
//methods
	bool containsElf(const Elf& elf) const;
	ElfTeam& addElf(const Elf& elf);
	void printElfTeam() const;
	double getTeamAgeAbillityRatio() const;
//operators
	ElfTeam& operator=(const ElfTeam& other_team);
	ElfTeam operator+(const ElfTeam& other_team);
	ElfTeam& operator+=(const ElfTeam& other_team);
	bool operator>(const ElfTeam& other_team) const;
	bool operator<(const ElfTeam& other_team) const;
};

