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

Book& Book::operator=(const Book& other_book) 
{
	if (*this != other_book)
	{
		this->book_name = other_book.book_name;
		this->book_author = other_book.book_author;
		this->year_published = other_book.year_published;	
	}
	else 
	{
		return *this;
	}
}

bool Book::operator==(const Book& other_book) const 
{
	return (this->book_name == other_book.book_name && this->book_author == other_book.book_author);
}

bool Book::operator!=(const Book& other_book) const 
{
	return !(*this == other_book);
}

bool Book::isLexicographicallyBiggerThan(const Book& other_book) const 
{
	int checker = 0;
	size_t length = this->book_name.length();
	for (size_t i = 0; i < length; i++)
	{
		if (this->book_name[i] > other_book.book_name[i])
		{
			checker = 1;
			break;
		}
		else if (other_book.book_name[i] > this->book_name[i])
		{
			checker = 2;
			break;
		}
	}
	return checker == 1;
}

bool Book::isLexicographicallyLesserThan(const Book& other_book) const
{
	return !(this->isLexicographicallyBiggerThan(other_book));
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