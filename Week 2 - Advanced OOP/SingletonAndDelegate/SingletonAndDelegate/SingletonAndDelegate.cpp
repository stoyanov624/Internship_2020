

#include <iostream>
#include "Worker.h"
#include "Shop.h"
#include "House.h"
#include "HouseOwner.h"
int main()
{
	//ProductNotAvailableSubject* subject = new ProductNotAvailableSubject();
	Shop* praktiker = new Shop();
	Worker ivan;
	praktiker->addObserverForProductNotAvailable(&ivan);

	ivan.addShop(praktiker);

	HouseOwner* ho = new HouseOwner();
	praktiker->addObserverForProductNotAvailable(ho);

	ivan.work();
	//HouseOwner* ho = new HouseOwner();

}

