#include "ElfTeam.h"

ElfTeam::ElfTeam() :team_name(), elf_team(), team_size(0) {}

ElfTeam::ElfTeam(const char _team_name[30]) 
{
	if (strlen(_team_name) > 30) 
	{
		strcpy_s(this->team_name, 1, "");
	}
	else 
	{
		strcpy_s(this->team_name, 30, _team_name);
	}
	
	this->team_size = 0;
}

ElfTeam& ElfTeam::addElf(const Elf& elf) 
{
	if (team_size >= 50) 
	{
		std::cout << "Team is full!" << std::endl;
		return *this;
	}
	else 
	{
		this->elf_team[team_size++] = elf;
		return *this;
	}
}

ElfTeam& ElfTeam::operator=(const ElfTeam& other_team)
{
	if (this != &other_team)
	{
		this->copy(other_team);
	}
	return *this;
}

ElfTeam ElfTeam::operator+(const ElfTeam& other_team) 
{
	ElfTeam result;
	size_t SIZE = other_team.team_size + this->team_size;
	if (this->team_size > 50) 
	{
		return *this;
	}
	else 
	{
		for (size_t i = 0; i < this->team_size; i++)
		{
			result.addElf(this->elf_team[i]);
		}

		for (size_t i = this->team_size; i < SIZE; i++)
		{
			result.addElf(other_team.elf_team[i]);
		}
		return result;
	}
}

bool ElfTeam::operator>(const ElfTeam& other_team) const
{
	return this->getTeamAgeAbillityRatio() > other_team.getTeamAgeAbillityRatio();
}

bool ElfTeam::operator<(const ElfTeam& other_team) const 
{
	return !(*this > other_team);
}

double ElfTeam::getTeamAgeAbillityRatio() const 
{
	int age_sum = 0;
	int abillities_sum = 0;

	for (size_t i = 0; i < this->team_size; i++)
	{
		age_sum += elf_team[i].getElfAge();
		abillities_sum += elf_team[i].getElfAbillity();
	}

	return (double)age_sum / abillities_sum;
}

void ElfTeam::printElfTeam() const 
{
	std::cout << "Team " << this->team_name << ':' << std::endl;
	for (size_t i = 0; i < this->team_size; i++)
	{
		this->elf_team[i].printElf();
		std::cout << std::endl;
	}
}