//
// Created by consent_ on 17-Mar-25.
//

#ifndef PATRON_V1_H
#define PATRON_V1_H

#include <string>
#include <iostream>

class patron
{
	//==================================СВОЙСТВА======================================
	std::string name_;
	int library_card_num_;
	double library_fee_;

	//============================ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ======================================

	constexpr void validate() const;

public:

	bool is_debtor() const;

	//==================================КОНСТРУКТОРЫ======================================
	//patron(const std::string& name, const int& library_card_num);
	patron(const std::string& name, const int& library_card_num, double library_fee_ = 0.0);


	//==================================ГЕТТЕРЫ======================================

	std::string get_name() const;
	int get_library_card_num() const;
	double get_library_fee() const;

	//==================================СЕТТЕРЫ======================================

	void set_fee(const double& fee);

	//==================================ОПЕРАТОРЫ======================================

	friend std::ostream& operator<<(std::ostream& os, const patron& obj);

};

#endif //PATRON_V1_H