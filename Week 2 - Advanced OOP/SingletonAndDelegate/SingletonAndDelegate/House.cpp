#include "House.h"

House::House(const std::string& _address) : address(_address) {}

House* House::getInstance(const std::string& adress) {
	if (House::singleton == nullptr) {
		House::singleton = new House(adress);
	}
	return House::singleton;
}

House* House::singleton = nullptr;