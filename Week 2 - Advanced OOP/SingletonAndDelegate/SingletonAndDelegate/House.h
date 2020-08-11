#pragma once
#include <iostream>
#include <string>
class House {
private:
	std::string address;
	static House* singleton;

	House(const std::string& _address);
public:
	House(const House& other) = delete;
	House& operator=(const House& other) = delete;

	static House* getInstance(const std::string& address = "");
};




