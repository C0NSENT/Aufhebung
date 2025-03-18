//
// Created by consent_ on 17-Mar-25.
//

#include "../headers/library.h"

#include <ranges>

//============================ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ======================================

bool library::is_patron_in_library(const patron& patron)
{
	const auto it = std::ranges::find(patrons_, patron );

	return (it != patrons_.end());
}

bool library::is_book_in_library(const book& book)
{
	const auto it = std::ranges::find(books_, book );
	return (it != books_.end());
}

//============================ОПЕРАТОРЫ======================================

//============================КОНСТРУКТОРЫ======================================

library::library()
= default;

library::library(const std::vector<patron> &patrons, const std::vector<book> &books)
{
	this->patrons_ = patrons;
	this->books_ = books;
	this->transactions_;
}

//============================МЕТОДЫ======================================

void library::add_patron(const patron &patron)
{
	if (is_patron_in_library(patron))
		throw std::logic_error("patron is already in library");

	this->patrons_.push_back(patron);
}

void library::add_book(const book &book)
{
	if (is_book_in_library(book))
		throw std::logic_error("book is already in library");

	this->books_.push_back(book);
}

void library::check_out(const patron &patron, const book &book, const date &date)
{
	if (!is_patron_in_library(patron))
		throw std::logic_error("patron is not in library");
	if (!is_book_in_library(book))
		throw std::logic_error("book is not in library");
	if (patron.is_debtor())
		throw std::logic_error("patron owes a fee");

	transactions_.push_back(transaction{book, patron, date});
}

//============================ГЕТТЕРЫ======================================

std::vector<patron> library::get_patrons() const
{
	return patrons_;
}

std::vector<patron> library::get_debtors() const
{
	std::vector<patron> debtors;

	for (const auto &patron : patrons_) {
		if (patron.is_debtor())
			debtors.push_back(patron);
	}

	return debtors;
}



int main()
{
	book ulysses{"978-2-38226-147-7","Ulysses", "James Joyce", "1920-02-02", book::genre::fiction};

}
