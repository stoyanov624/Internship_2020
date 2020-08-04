#pragma once
#include "Book.h"
#include <functional>
#include <vector>
class Library
{
private:
	std::string library_name;
	std::vector<Book> books;
public:
//constructors
	Library();
	Library(const std::string& _library_name);
//setters&getters
	void setLibraryName(const std::string& _library_name);
	const std::string& getLibraryName() const;
	const std::vector<Book>& getLibraryBooks() const;
//methods
	bool containsBook(const Book& book) const;
	void swapBooks(Book& book1, Book& book2);
	Library& addBook(const Book& book);
	Library& removeBook(const Book& book);
	Library& sortBooks();
	void printByCritique(std::function<bool(Book)> critique);
	void printAllBooks() const;
};

