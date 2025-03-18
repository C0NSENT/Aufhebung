//
// Created by consent_ on 17-Mar-25.
//

#include "../headers/patron.h"

//============================ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ======================================

constexpr void patron::validate() const
{
	if (library_card_num_ < 0)
		throw std::invalid_argument("library card number is negative");
	if (library_fee_ < 0)
		throw std::invalid_argument("library fee is negative");
}

bool patron::is_debtor() const {
	return (this->library_fee_ > 0);
}

//============================КОНСТРУКТОРЫ======================================

patron::patron(const std::string &name, const int &library_card_num, double library_fee)
	: name_(name),
	library_card_num_(library_card_num),
	library_fee_(library_fee)
{
	validate();
}

//==================================ГЕТТЕРЫ======================================

std::string patron::get_name() const { return name_; }
int patron::get_library_card_num() const { return library_card_num_; }
double patron::get_library_fee() const { return this->library_fee_; }

//==================================СЕТТЕРЫ======================================

void patron::set_fee(const double &fee) {
	library_fee_ = fee;
	validate();
}

//==================================ОПЕРАТОРЫ======================================

std::ostream& operator<<(std::ostream& os, const patron& obj) {
	os << obj.get_name() << "\n"
	<< obj.get_library_card_num() << "\n"
	<< obj.get_library_fee();

	return os;
}

bool patron::operator==(const patron& other) const
{
	return (this->name_ == other.name_)
		&& (this->library_card_num_ == other.library_card_num_)
		&& (this->library_fee_ == other.library_fee_);
}

bool patron::operator!=(const patron& other) const {return !(operator==(other));}