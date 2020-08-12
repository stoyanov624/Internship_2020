#pragma once
#include <string>
#include <vector>
class ShopDelegate {
public:
	virtual void productDoesNotExist() = 0;
	virtual void productNotAvailable() = 0;
	virtual void brandNotAvailable() = 0;
};

class ProductNotAvailableObserver {
public:
	virtual void update() = 0;
};

//observable
class ProductNotAvailableSubject {
private:
	std::vector<ProductNotAvailableObserver*> observers;
public:
	void addObserver(ProductNotAvailableObserver* observer) {
		this->observers.push_back(observer);
	}

	void notify() {
		for (ProductNotAvailableObserver* observer : observers) { //observers.begin()
			observer->update();
		}
	}
};

class Shop {
private:
	//ShopDelegate* delegate;
	ProductNotAvailableSubject* productNotAvailable;
public:
	//Shop(ShopDelegate* _delegate) : delegate(_delegate) {}
	Shop() { 
		productNotAvailable = new ProductNotAvailableSubject();
	}
	class Product {};

	Product* buyProduct(const std::string& product) {
		//delegate->productNotAvailable();
		productNotAvailable->notify();
		return nullptr;
	}

	void addObserverForProductNotAvailable(ProductNotAvailableObserver* newObserver) {
		this->productNotAvailable->addObserver(newObserver);
	}
};


