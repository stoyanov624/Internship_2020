#pragma once
#include <iostream>
#include <cstring>

class Book
{
private:
	std::string book_name;
	std::string book_author;
	int year_published;
public:
//constructors
	Book();
	Book(const std::string& _book_name,const std::string& _book_author,const int& _year_published);
	Book(const std::string& _book_name,const std::string& _book_author);
//setters & getters
	void setBookName(const std::string& _book_name);
	void setBookAuthor(const std::string& _book_author);
	void setBookYear (const int& _year_published);
	const std::string& getBookName() const;
	const std::string& getBookAuthor() const;
	const int& getBookYear() const;
//operators
	Book& operator=(const Book& other_book);
	bool operator==(const Book& other_book) const;
	bool operator!=(const Book& other_book) const;
//methods
	bool isLexicographicallyBiggerThan(const Book& other_book) const;
	bool isLexicographicallyLesserThan(const Book& other_book) const;
	void printBook() const;
};

