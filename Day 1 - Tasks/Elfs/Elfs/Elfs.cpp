#include <iostream>
#include "Elf.h"
#include "ElfTeam.h"

const int ANALYSE_SIZE = 2;

void analyse(const ElfTeam teams[ANALYSE_SIZE]) 
{
	ElfTeam superior;
	superior = teams[0];
	for (size_t i = 0; i < ANALYSE_SIZE; i++)
	{
		if (teams[i] < teams[i + 1]) 
		{
			superior = teams[i + 1];
		}
	}
	superior.printElfTeam();
}

int main()
{
	Elf elf1("Dan40",169,10);
	Elf elf2("Petkan",140,8);
	Elf elf3("Legolas",90,15);
	ElfTeam eT1("Kikimoraaa");
	ElfTeam eT2("Qukamora");
	
	eT1.addElf(elf1);
	eT1.addElf(elf2);
	eT1.addElf(elf3);
	eT1.addElf(elf1);
	
	eT2.addElf(elf1);
	
	ElfTeam teams[ANALYSE_SIZE];
	teams[0] = eT1;
	teams[1] = eT2;

	std::cout << eT1.getTeamAgeAbillityRatio() << std::endl;
	std::cout << eT2.getTeamAgeAbillityRatio() << std::endl;
	analyse(teams);
}
