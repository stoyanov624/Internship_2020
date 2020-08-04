

#include <iostream>
#include "Elf.h"
#include "ElfTeam.h"
int main()
{
	Elf elf1("Dan40",169,10);
	Elf elf2("Petkan",140,8);
	Elf elf3("Legolas",90,15);
	ElfTeam eT1("Kikimoraaa");
	ElfTeam eT2("KakaMora");
	//elf1.printElf();
	eT1.addElf(elf1);
	eT1.addElf(elf2);
	eT1.addElf(elf3);
	eT1.addElf(elf1);

	eT2.addElf(elf1);

	ElfTeam result;

	eT1 = eT2;
	
}
