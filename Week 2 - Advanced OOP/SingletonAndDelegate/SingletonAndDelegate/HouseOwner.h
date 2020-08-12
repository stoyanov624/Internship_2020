#pragma once
#include <iostream>
#include "Shop.h"

class HouseOwner : public ProductNotAvailableObserver {
public:
	void update() {
		std::cout << "House owner notified that product is not available";
	}
};
