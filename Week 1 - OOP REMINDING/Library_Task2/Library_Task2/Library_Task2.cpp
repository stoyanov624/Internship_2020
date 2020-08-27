
#include <iostream>
#include "Book.h"
#include "Library.h"

bool critiqueStartsWithA(const Book& book) 
{
	return (book.getBookName()[0] == 'a' || book.getBookName()[0] == 'A');
}

int main()
{
	Book book1("Bai Ganio", "Aleko", 1899);
	Book book2("Alll", "Aleko", 1899);
	Book book3("Kapone", "Aleko", 1899);
	Book book4("Bible", "Aleko", 1899);
	Book book5("LOTR", "Aleko", 1899);
	Book book6("C", "Aleko");
	Book book7("Zetro", "Aleko");
	
	
	Library lib1("FMI Library");
	
	lib1.addBook(book1);
	lib1.addBook(book2);
	lib1.addBook(book3);
	lib1.addBook(book7);
	lib1.addBook(book4);
	lib1.addBook(book5);
	lib1.addBook(book6);

	lib1.sortBooks();
	lib1.printByCritique(critiqueStartsWithA);
	
	
}

