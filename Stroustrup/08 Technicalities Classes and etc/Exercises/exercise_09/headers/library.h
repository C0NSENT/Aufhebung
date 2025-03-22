//
// Created by consent_ on 17-Mar-25.
//

//Create a Library class. Include vectors of Books and Patrons.
//Include a struct called Transaction to record when a book is checked out.
//Have it include a Book, a Patron, and a Date.
//Make a vector of Transactions to keep a record of which books are out.
//Create functions to add books to the library, add patrons to the library,
//and check out books. Whenever a user checks out a book,
//have the library make sure that both the user and the book are in the library.
//If they aren’t, report an error.
//Then check to make sure that the user owes no fees.
//If the user does, report an error.
//If not, create a Transaction, and place it in the vector of Transactions.
//Also write a function that will return
//a vector that contains the names of all Patrons who owe fees.

#ifndef LIBRARY_V1_H
#define LIBRARY_V1_H

#include <vector>

#include "patron.h"
#include "date.h"
#include "book.h"

class library
{
	struct transaction
	{
		book book_;
		patron patron_;
		date transaction_date_;

	};

	//==================================СВОЙСТВА======================================

	std::vector<patron> patrons_;
	std::vector<book> books_;
	std::vector<transaction> transactions_;

	//============================ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ======================================

	bool is_patron_in_library(const patron& patron);
	bool is_book_in_library(const book& book);

public:

	//============================ОПЕРАТОРЫ======================================



	//============================КОНСТРУКТОРЫ======================================

	library();
	library(const std::vector<patron>& patrons, const std::vector<book>& books);

	//============================МЕТОДЫ======================================


	void add_patron(const patron& patron);
	void add_book(const book& book);
	void check_out(const patron& patron, const book& book, const date& date);

	//============================ГЕТТЕРЫ======================================

	std::vector<patron> get_patrons() const;
	std::vector<patron> get_debtors() const;

};



#endif //LIBRARY_V1_H
