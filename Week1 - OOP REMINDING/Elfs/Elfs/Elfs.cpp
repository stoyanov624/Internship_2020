#include <iostream>
#include "Elf.h"
#include "ElfTeam.h"
#include <algorithm>


template <size_t ANALYSE_SIZE>
void analyse(const ElfTeam(& teams)[ANALYSE_SIZE]) 
{
	//size_t team_count = sizeof(teams) / sizeof(ElfTeam);
	ElfTeam superior;
	superior = teams[0];
	for (size_t i = 1; i < ANALYSE_SIZE; i++)
	{
		superior = std::max(superior,teams[i]);
		//if (teams[i] < teams[i + 1]) 
		//{
		//	superior = teams[i + 1];
		//}
	}
	std::cout << "The superior team is:" << std::endl;
	superior.printElfTeam();
}

int main()
{
	Elf elf1("Dan40",169,10);
	Elf elf2("Petkan",140,8);
	Elf elf3("Legolas",90,15);
	ElfTeam eT1("Kikimoraaa");
	ElfTeam eT2("Qukamora");
	ElfTeam eT3("Empty");
	
	eT1.addElf(elf1);
	eT1.addElf(elf2);
	eT1.addElf(elf3);
	eT1.addElf(elf1);
	
	eT2.addElf(elf1);
	
	ElfTeam teams[3];
	teams[0] = eT1;
	teams[1] = eT2;
	teams[2] = eT3;

	std::cout << eT1.getTeamAgeAbillityRatio() << std::endl;
	std::cout << eT2.getTeamAgeAbillityRatio() << std::endl;
	std::cout << eT3.getTeamAgeAbillityRatio() << std::endl;
	analyse(teams);
}
