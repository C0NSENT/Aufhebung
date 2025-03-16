//
// Created by consent_ on 14-Mar-25.
//

//This exercise and the next few require you to design and implement a Book class,
//such as you can imagine as part of software for a library. Class Book should have members for the ISBN,
//title, author, and copyright date. Also store data on whether or not the book is checked out.
//Create functions for returning those data values. Create functions for checking a book in and out.
//Do simple validation of data entered into a Book; for example,
//accept ISBNs only of the form n−n−n−x where n is an integer and x is a digit or a letter. Store an ISBN as a string

#include "../headers/book_v1.h"
#include <regex>

//============================ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ======================================

bool book::is_valid() {
	return (is_isbn_valid());
}

bool book::is_isbn_valid() const
{
	const std::regex pattern(R"(\d+-\d+-\d+-\d+-[0-9A-Z])");
	return std::regex_match(this->isbn_, pattern);
}

//============================КОНСТРУКТОРЫ======================================

book::book(const std::string &isbn, const std::string &title, const std::string &author,
	const date &copyright_date, const bool &is_checked_out)
{
	this->isbn_ = isbn;
	this->title_ = title;
	this->author_ = author;
	this->copyright_date_ = copyright_date;
	this->is_checked_out_ = is_checked_out;

	if (!is_isbn_valid()) {
		throw std::invalid_argument("book::book(): invalid book isbn");
	}
}

//============================ГЕТТЕРЫ======================================

std::string book::get_isbn() const {
	return this->isbn_;
}
std::string book::get_title() const {
	return this->title_;
}
std::string book::get_author() const {
	return this->author_;
}
date book::get_copyright_date() const {
	return this->copyright_date_;
}
bool book::is_checked_out() const {
	return this->is_checked_out_;
}

int main()
{
	date date1{"1922-02-2"};
	book book1 {"978-2-382226-147-7", "Ulysses", "James Joyce", date1, true};

}

