#include "ElfTeam.h"

void ElfTeam::rename(const char* _team_name)
{
	if (strlen(_team_name) > 30)
	{
		strcpy_s(this->team_name, 1, "");
	}
	else
	{
		strcpy_s(this->team_name, 30, _team_name);
	}
}

ElfTeam::ElfTeam() :team_name(), elf_team(), team_size(0) {}

ElfTeam::ElfTeam(const char* _team_name) : elf_team(), team_size(0)
{
	this->rename(_team_name);
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

bool ElfTeam::containsElf(const Elf& elf) const
{
	for (size_t i = 0; i < this->team_size; i++)
	{
		if (this->elf_team[i] == elf) 
		{
			return true;
		}
	}
	
	return false;
}

ElfTeam& ElfTeam::operator=(const ElfTeam& other_team)
{
	//Elf def_elf;
	//std::fill_n(elf_team, 50,def_elf);
	
	this->rename(other_team.team_name);

	this->team_size = other_team.team_size;
	
	for (size_t i = 0; i < this->team_size; i++)
	{
		this->elf_team[i] = other_team.elf_team[i];
	}

	return *this;
}

ElfTeam ElfTeam::operator+(const ElfTeam& other_team)
{
	ElfTeam result;

	result.team_name[0] = other_team.team_name[0];
	result.team_name[1] = '&';
	result.team_name[2] = this->team_name[0];

	size_t SIZE = other_team.team_size + this->team_size;
	if (this->team_size > 50)
	{
		return *this;
	}

	for (size_t i = 0; i < this->team_size; i++)
	{
		if (!result.containsElf(elf_team[i]))
		{
			result.addElf(this->elf_team[i]);
		}
	}

	for (size_t i = this->team_size, j = 0; i < SIZE && i < 50; i++, j++)
	{
		if (!result.containsElf(other_team.elf_team[j]))
		{
			result.addElf(other_team.elf_team[j]);
		}
	}
	return result;

}

ElfTeam& ElfTeam::operator+=(const ElfTeam& other_team) 
{
	*this = *this + other_team;
	return *this;
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
	if (abillities_sum == 0) 
	{
		return 0;
	}
	return (double)age_sum / abillities_sum;
}

void ElfTeam::printElfTeam() const 
{
	std::cout << "Team " << this->team_name << ':' << std::endl;
	for (size_t i = 0; i < this->team_size; i++)
	{
		std::cout << elf_team[i];
	}
	std::cout << std::endl;
}