#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <assert.h>
#include <optional>

template <class U,class V >
class Relation
{
private:
	std::vector<std::pair<U, V>> relation;

	bool contains_pair(const std::pair<U, V>& pair_check) const;
public:
//constructors
	Relation();
	Relation(const std::vector<U>& set1,const std::vector<V>& set2);
	Relation(const Relation& other_relation);
//methods
	bool is_Related(const std::pair<U, V>& pair_check) const;
	bool is_Function() const;
	void addPair(const std::pair<U, V>& pair_to_add);
	void print_relation() const;
//operators
	V operator[](const U& u) const;
	Relation operator+(const Relation& other_relation) const;
	Relation<U,V>& operator+=(const Relation& other_relation);
	
};

//helper
template <class U, class V>
bool Relation<U, V>::contains_pair(const std::pair<U, V>& pair_check) const 
{
	for (size_t i = 0, SIZE = this->relation.size(); i < SIZE; i++)
	{
		if (this->relation[i].first == pair_check.first && this->relation[i].second == pair_check.second)
		{
			return true;
		}
	}

	return false;
}

// CONSTRUCTORS

template <class U, class V>
Relation<U, V>::Relation() : relation() {}

template <class U, class V>
Relation<U, V>::Relation(const std::vector<U>& set1,const std::vector<V>& set2)
{
	size_t size_set1 = set1.size();
	size_t size_set2 = set2.size();

	for (size_t i = 0; i < size_set1; i++)
	{
		for (size_t j = 0;  j < size_set2;  j++)
		{
			relation.push_back(std::make_pair(set1[i], set2[j]));
		}
	}
}

template <class U, class V>
Relation<U, V>::Relation(const Relation& other_relation) 
{
	this->relation = other_relation.relation;
}

//METHODS

template <class U, class V>
bool Relation<U, V>::is_Related(const std::pair<U, V>& pair_check) const 
{
	return (this->contains_pair(pair_check));
}

template <class U, class V>
bool Relation<U, V>::is_Function() const
{
	const size_t SIZE = this->relation.size();
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = i + 1; j < SIZE; j++)
		{
			if (this->relation[i].first == this->relation[j].first) 
			{
				return false;
			}
		}
	}
	return true;
}

template <class U, class V>
void Relation<U, V>::addPair(const std::pair<U, V>& pair_to_add) 
{
	this->relation.push_back(pair_to_add);
}

template <class U, class V>
void Relation<U, V>::print_relation() const
{
	std::cout << "{";
	for (size_t i = 0, SIZE = this->relation.size(); i < SIZE; i++)
	{
		std::cout << "(" << relation[i].first << "," << relation[i].second << ")";
	}
	std::cout << "}" << std::endl;
}

//OPERATORS

template <class U, class V>
V Relation<U, V>::operator[](const U& u) const
{
	for (size_t i = 0, SIZE = this->relation.size(); i < SIZE; i++)
	{
		std::pair<U, V> pair_check = std::make_pair(u, relation[i].second);
		if (this->contains_pair(pair_check))
		{
			return relation[i].second;
		}
	}
	std::optional<V> i;
	if (i) 
	{
		std::cout << "Okay\n";
	}
	else 
	{
		std::cout << "No such v\n";
	}
}

template <class U, class V>
Relation<U,V> Relation<U, V>::operator+(const Relation& other_relation) const
{
	Relation result(*this);
	//make copy constuctor;

	const size_t size_our_relation = this->relation.size();
	const size_t size_other_relation = other_relation.relation.size();
	const size_t size_combined_relations = size_our_relation + size_other_relation;
	
	for (size_t i = size_our_relation,j = 0; i < size_combined_relations; i++,j++)
	{
		if (!result.contains_pair(other_relation.relation[j])) 
		{
			result.addPair(other_relation.relation[j]);
		}
	}

	return result;
}

template <class U, class V>
Relation<U, V>& Relation<U, V>::operator+=(const Relation<U,V>& other_relation) 
{
	*this = *this + other_relation;
	return *this;
}








