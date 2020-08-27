
#include <iostream>
#include <utility>
#include <vector>
#include "Relation.h"
int main()
{
	std::pair<int, int> pair = {1,4};
	std::vector<int> v1 = { 1,2,3 };
	std::vector<int> v2 = { 4,5,6 };
	std::vector<int> v3 = {1};

	Relation<int, int> r1(v1, v2);
	Relation<int, int> r2(v2, v1);
	Relation<int, int> r3;

	r1[500];
}