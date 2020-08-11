#pragma once
#include "Shop.h"

class Worker:ShopDelegate {
private:
	Shop ikea;
public:
	Worker() :ikea(this) {}
};


