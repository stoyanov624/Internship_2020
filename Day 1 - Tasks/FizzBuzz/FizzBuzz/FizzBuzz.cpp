
#include <iostream>
#include <map>

int main()
{
	std::map<int, std::string> keys;
	keys[3] = "Fizz";
	keys[7] = "Buzz";
	keys[8] = "Cozz";

	for (size_t i = 1; i <= 100; i++) {
		std::string str;

		for (auto it = keys.begin(); it != keys.end(); ++it) {
			if (i % it->first == 0)
				str.append(it->second);
		}

		if (str.empty())
			std::cout << i << std::endl;
		else
			std::cout << str << std::endl;
	}
}
