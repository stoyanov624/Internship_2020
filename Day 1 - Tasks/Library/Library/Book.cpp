#include "Book.h"

Book::Book() : book_name(), book_author(), year_published(0) {}

Book::Book(const std::string& _book_name, const std::string& _book_author, const int& _year_published) : book_name(_book_name), book_author(_book_author), year_published(_year_published) {}

Book::Book(const std::string& _book_name, const std::string& _book_author) : book_name(_book_name), book_author(_book_author), year_published(-1) {}

void Book::setBookName(const std::string& _book_name) 
{
	this->book_name = _book_name;
}

void Book::setBookAuthor(const std::string& _book_author)
{
	this->book_author = _book_author;
}

void Book::setBookYear(const int& _year_published) 
{
	this->year_published = _year_published;
}

const std::string& Book::getBookName() const 
{
	return this->book_name;
}

const std::string& Book::getBookAuthor() const 
{
	return this->book_author;
}

const int& Book::getBookYear() const 
{
	return this->year_published;
}

void Book::printBook() const 
{
	std::cout << "Book name: " << book_name << std::endl;
	std::cout << "Book author: " << book_author << std::endl;
	if (year_published != -1) 
	{
		std::cout << "Year of publishment: " << year_published << std::endl;
	}

}