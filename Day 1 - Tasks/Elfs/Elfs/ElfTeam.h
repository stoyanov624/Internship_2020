#pragma once
#include <iostream>
#include "Elf.h"
class ElfTeam
{
private:
	char team_name[30];
	Elf elf_team[50];
	size_t team_size;

public:
	ElfTeam();
	ElfTeam(const char _team_name[30]);
	ElfTeam& addElf(const Elf& elf);
	void printElfTeam() const;
	double getTeamAgeAbillityRatio() const;
	ElfTeam& operator=(const ElfTeam& other_team);
	ElfTeam operator+(const ElfTeam& other_team);
	bool operator>(const ElfTeam& other_team) const;
	bool operator<(const ElfTeam& other_team) const;
};

