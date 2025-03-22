//
// Created by consent_ on 14-Mar-25.
//

#include "../headers/book.h"
#include <regex>
#include <vector>

std::ostream& operator<<(std::ostream& os, const book::genre& genre)
{
	const std::vector<std::string> genre_names{ "fiction", "nonfiction", "periodical",
		"biography", "children"};

	os << genre_names.at(static_cast<int>(genre));
	return os;
}


//============================ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ======================================

bool book::is_valid() {
	return (is_isbn_valid());
}

bool book::is_isbn_valid() const
{

	const std::regex isbn13_pattern(R"(^(978|979)-\d{1,5}-\d{1,7}-\d{1,6}-\d$)");
	const std::regex isbn10_pattern(R"(^\d{1,5}-\d{1,7}-\d{1,6}-[0-9X]$)");

	return (std::regex_match(this->isbn_, isbn13_pattern)
		|| std::regex_match(this->isbn_, isbn10_pattern));
}

//============================КОНСТРУКТОРЫ======================================

book::book(const std::string &isbn, const std::string &title, const std::string &author,
	const date &copyright_date, const genre& genre, bool is_checked_out)
{
	this->isbn_ = isbn;
	this->title_ = title;
	this->author_ = author;
	this->copyright_date_ = copyright_date;
	this->genre_ = genre;
	this->is_checked_out_ = is_checked_out;

	if (!is_isbn_valid()) {
		throw std::invalid_argument("book::book(): invalid book isbn");
	}
}

book::book(const std::string &isbn, const std::string &title,
	const std::string &author, const std::string &copyright_date,
	const genre &genre, bool is_checked_out)
	: book(isbn, title, author,
	  date{copyright_date}, genre, is_checked_out)
{
	if (!is_isbn_valid())
		throw std::invalid_argument("book::book(): invalid book isbn");
}

//============================ОПЕРАТОРЫ======================================

bool book::operator==(const book &other) const {
	return this->isbn_ == other.isbn_;
}

bool book::operator!=(const book &other) const {
	return this->isbn_ != other.isbn_;
}

std::ostream& operator<<(std::ostream& os, const book& obj)
{
	os << obj.get_title() << "\n";
	os << obj.get_author() << "\n";
	os << obj.get_isbn() << "\n";
	os << obj.get_genre();

	return os;
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

book::genre book::get_genre() const {
	return this->genre_;
}

bool book::is_checked_out() const {
	return this->is_checked_out_;
}


