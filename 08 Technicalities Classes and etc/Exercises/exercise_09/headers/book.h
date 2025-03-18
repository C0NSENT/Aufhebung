//
// Created by consent_ on 16-Mar-25.
//


#ifndef BOOK_V1_H
#define BOOK_V1_H

#include "date.h"

class book
{
public:
	//==================================ENUM CLASS GENRE=====================================

	enum class genre
	{
		fiction, nonfiction, periodical, biography, children
	};

	friend std::ostream& operator<<(std::ostream& os, const genre& book);

private:

	//==================================СВОЙСТВА======================================

	std::string isbn_;
	std::string title_;
	std::string author_;
	date copyright_date_;
	genre genre_;
	bool is_checked_out_;

	//============================ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ======================================

	bool is_valid();
	bool is_isbn_valid() const;
	bool is_isbn_checksum_valid() const;

public:
	//============================КОНСТРУКТОРЫ======================================

	book();
	book(const std::string& isbn, const std::string& title, const std::string& author,
		const date& copyright_date, const genre& genre,  bool is_checked_out = false);
	book (const std::string& isbn, const std::string& title, const std::string& author,
		const date& copyright_date, const genre& genre, bool is_checked_out = false);

	//============================ОПЕРАТОРЫ======================================

	bool operator==(const book& other) const;
	bool operator!=(const book& other) const;

	friend std::ostream& operator<<(std::ostream& os, const book& obj);

	//============================ГЕТТЕРЫ======================================
	std::string get_isbn() const;
	std::string get_title() const;
	std::string get_author() const;
	date get_copyright_date() const;
	genre get_genre() const;
	bool is_checked_out() const;

};

#endif //BOOK_V1_H