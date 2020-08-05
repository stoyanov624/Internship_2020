#pragma once
#include "Book.h"
#include <functional>
#include <vector>
class Library
{
private:
	std::string library_name;
	std::vector<Book> books;

	void swap(Book& b1, Book& b2);
	void sort(std::function<bool(Book, Book)> f);
public:
//constructors
	Library();
	Library(const std::string& _library_name);
//setters&getters
	void setLibraryName(const std::string& _library_name);
	const std::string& getLibraryName() const;
	const std::vector<Book>& getLibraryBooks() const;
//methods
	void sortByTitle();
	void sortByYear();
	bool containsBook(const Book& book) const;
	void swapBooks(Book& book1, Book& book2);
	Library& addBook(const Book& book);
	Library& removeBook(const Book& book);
	void printByCriteria(std::function<bool(Book)> critique);
	void printAllBooks() const;
};

