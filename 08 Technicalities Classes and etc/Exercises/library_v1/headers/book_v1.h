//
// Created by consent_ on 16-Mar-25.
//

//This exercise and the next few require you to design and implement a Book class,
//such as you can imagine as part of software for a library. Class Book should have members for the ISBN,
//title, author, and copyright date. Also store data on whether or not the book is checked out.
//Create functions for returning those data values. Create functions for checking a book in and out.
//Do simple validation of data entered into a Book; for example,
//accept ISBNs only of the form n−n−n−x where n is an integer and x is a digit or a letter. Store an ISBN as a string

#ifndef BOOK_V1_H
#define BOOK_V1_H

#endif //BOOK_V1_H

#include "date.h"

class book
{
	//==================================СВОЙСТВА======================================

	std::string isbn_;
	std::string title_;
	std::string author_;
	date copyright_date_;
	bool is_checked_out_;

	//============================ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ======================================

	bool is_valid();
	bool is_isbn_valid() const;

public:
	//============================КОНСТРУКТОРЫ======================================

	book();
	book(const std::string& isbn, const std::string& title, const std::string& author,
		const date& copyright_date, const bool& is_checked_out);


	//============================ГЕТТЕРЫ======================================
	std::string get_isbn() const;
	std::string get_title() const;
	std::string get_author() const;
	date get_copyright_date() const;
	bool is_checked_out() const;

};