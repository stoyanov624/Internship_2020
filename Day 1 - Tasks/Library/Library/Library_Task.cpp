
#include <iostream>
#include "Book.h"

int main()
{
	Book book1("Bai Ganio","Aleko",1899);
	Book book2("Bai Ganio","Aleko");
	book1.printBook();
	book1.setBookAuthor("Shtasliveca");
	std::cout << "\n";
	

	std::cout << book1.getBookName();
}

