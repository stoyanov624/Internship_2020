#pragma once
#include "Shop.h"
#include <cassert>
class Worker:ShopDelegate, public ProductNotAvailableObserver {
private:
	Shop* ikea;
public:
	Worker() : ikea(nullptr) {}

	void work() 
	{
		assert(ikea);
		ikea->buyProduct("Some product");
	}

	void update() {
		std::cout << "Worker updated that product is not available!\n";
	}

	void productDoesNotExist() {

	}

	void addShop(Shop* shop) {
		this->ikea = shop;
	}

	void productNotAvailable() {

	}

	void brandNotAvailable() {

	}
};


