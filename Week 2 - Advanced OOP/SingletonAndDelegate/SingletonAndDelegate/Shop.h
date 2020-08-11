#pragma once
#include <string>
class ShopDelegate {
public:
	virtual void productDoesNotExist() = 0;
	virtual void productNotAvailable() = 0;
	virtual void brandNotAvailable() = 0;
};

class Shop {
private:
	ShopDelegate* delegate;
public:
	Shop(ShopDelegate* _delegate) : delegate(_delegate) {}
	class Product {};

	Product* buyProduct(const std::string& product) {
		delegate->productNotAvailable();
		return nullptr;
	}
};


