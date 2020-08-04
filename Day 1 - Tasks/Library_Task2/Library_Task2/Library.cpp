#include "Library.h"

Library::Library() : library_name(), books() {}

Library::Library(const std::string& _library_name) : library_name(_library_name), books() {}

void Library::setLibraryName(const std::string& _library_name) 
{
	this->library_name = _library_name;
}

const std::string& Library::getLibraryName() const
{
	return this->library_name;
}

const std::vector<Book>& Library::getLibraryBooks() const 
{
	return this->books;
}

bool Library::containsBook(const Book& book) const 
{
	for (Book b : books)
	{
		if (b == book)
		{
			return true;
		}
	}

	return false;
}

void Library::swapBooks(Book& book1, Book& book2) 
{
	Book temp = book1;
	book1 = book2;
	book2 = temp;
}

Library& Library::addBook(const Book& book) 
{
	if (this->containsBook(book))
	{
		std::cout << "The book " << book.getBookName() << " already exists in the library!" << std::endl;
		return *this;
	}
	
	books.push_back(book);
	return *this;
}

Library& Library::removeBook(const Book& book) 
{
	if (!this->containsBook(book)) 
	{
		std::cout << "The book " << book.getBookName() << " does NOT exists in the library!" << std::endl;
		return *this;
	}
	else 
	{
		std::vector<Book> modified_books;
		for (Book b : books)
		{
			if (b != book)
			{
				modified_books.push_back(b);
			}
		}

		books = modified_books;
		return *this;
	}
}

Library& Library::sortBooks() 
{
	size_t books_count = books.size();
	for (size_t i = 0; i < books_count - 1; i++)
	{
		for (size_t j = 0; j < books_count - i - 1; j++)
		{
			if (books[j].isLexicographicallyBiggerThan(books[j + 1])) 
			{
				this->swapBooks(books[j], books[j + 1]);
			}
		}
	}
	return *this;
}

void Library::printByCritique(std::function<bool(Book)> critique) 
{
	for(Book b : books)
	{
		if (critique(b)) 
		{
			b.printBook();
		}
	}
}

void Library::printAllBooks() const 
{
	std::cout << "Books in " << this->library_name << ":" << std::endl;
	for (Book b : books) 
	{
		b.printBook();
		std::cout << std::endl;
	}
}