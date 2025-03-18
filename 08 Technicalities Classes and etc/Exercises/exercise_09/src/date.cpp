//
// Created by consent_ on 11-Mar-25.
//

#include "../headers/date.h"
#include <array>
#include <regex>


//===========================ОПЕРАТОРЫ================================

month operator++(month& m)
{
	m = (m==month::dec) ? month::jan : month{static_cast<int>(m)+1};
	return m;
}


std::ostream& operator<<(std::ostream &os, const month &obj)
{
	const static std::array<std::string, 13> arr_str_months{"not a month", "january", "february", "march",
									"april", "may", "june",
									"july", "august", "september",
									"october", "november", "december"};

	return os << arr_str_months.at(static_cast<int>(obj));
}





date& date::operator=(const date& obj)
= default;

std::ostream& operator<<(std::ostream& os, const date& obj)
{
	os << obj.y <<"/"<< obj.m <<"/"<<obj.d;
	return os;
}

//===========================ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ================================


bool date::is_valid()
{
	if (m == month::feb)
	{
		if (is_leap(y) && d == 29) return false;
	}

	if (d >  days_in_month(m, y)) return false;

	if (y < 0) return false;

	return true;
}

bool date::is_str_format_valid(const std::string& str_date)
{
	std::regex pattern(R"(^\d{4}-\d{1,2}-\d{1,2}$)");
	return std::regex_match(str_date, pattern);
}

bool date::is_leap(const int &y) {
		return (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0));
}

month date::to_month(const int& num)
{
	if (num < 1 || num > 12)
		throw std::invalid_argument("Ты чо шизоид? В году 12 месяцев");

	return month{num};
}

int date::days_in_year(const int& y)
{
	std:: cout << "В годе - " << y << (is_leap(y) ? ": 366" : ": 365") << "\n";
	return (is_leap(y)) ? 366 : 365;
}


int date::days_in_month(const month &m, const int& y)
{
	switch (to_int(m)) {
		case 2: return is_leap(y) ? 29 : 28;

		case 1: case 3: case 5: case 7:
		case 8: case 10: case 12:
		return 31;

		default: return 30;
	}
}

date date::str_to_date(const std::string &str_date)
{
	if (!is_str_format_valid(str_date))
		throw std::invalid_argument("Date::str_to_date() - Неверный формат строки");

	std::array<std::string, 3> v_str_separated;

	try
	{
		int it = 0;
		for (int i = 0; i < str_date.size(); i++)
		{
			if (!isdigit(str_date.at(i))) {
				it++;
				i++;
			}
			v_str_separated.at(it).push_back(str_date.at(i));
		}
	}
	catch (std::out_of_range e)
	{
		throw std::out_of_range(e.what());
	}

	std::array<int, 3> v_str_to_int;


	for (int i = 0; i < v_str_separated.size(); i++)
	{
			v_str_to_int.at(i) = std::stoi(v_str_separated.at(i));
	}

	date obj{v_str_to_int.at(0),
		to_month(v_str_to_int.at(1)),
		v_str_to_int.at(2)};

	return obj;
}

int date::date_to_days(const date &date)
{
	return date_to_days(date, 1);
}

date date::days_to_date(const int& days)
{
	return days_to_date(days, 1);
}

int date::date_to_days(const date &date, const int &base_year)
{
	int days{date.d};
	std::cout<< days << " days\n";


	for (int i = 1; i < to_int(date.m); i++) {
		days+= days_in_month(month{i}, date.y);

		std::cout<< days << " days in " << month{i} << "\n";
	}

	for (int i = base_year; i < date.y; i++) {
		days += days_in_year(i);
		std::cout<< days << " days\n";
	}

	std::cout << "date_to_days: " << days << "\n";
	return days;
}

date date::days_to_date(int days, const int &base_year)
{
	int years{base_year};
	while (days_in_year(years) < days ) {
		days-= days_in_year(years);
		years++;
	}

	int m{1};
	while (days_in_month(month{m}, years) < days) {
		days -= days_in_month(month{m}, years);
		m++;
	}
	return date(years, month{m}, days);
}


//===========================КОНСТРУКТОРЫ================================

date::date():date(1600, month::jan, 1){}

date::date(const std::string& s):date(str_to_date(s)){}

date::date(const int &y, const month &m, const int &d)
	: y(y), m(m), d(d)
{
	if (!is_valid())
		throw std::invalid_argument("Ваша дата - инвалид, соболезнуем");
}

date::date(const date &date)
{
	*this = date;
}

//===========================ИНТЕРФЕЙС================================

void date::add_day(const int &d)
{
	int days{d};
	const int base_year{this->y};

	std::cout<<"add_day " <<days << " days\n";

	days += date_to_days(*this, base_year);

	std::cout<<"add_day после функции date_to_days " <<days << " days\n";

	*this = date(days_to_date(days, base_year));
}

void date::add_month(const int& m)
{
	/*m += to_int(this->m);
	while (m > 12) {
		this->y++;
		m -= 12;
	}
	this->m = month{m};*/

	//add_day(m);
}

void date::add_year(const int &y)
{
	int leap_year_correction{0};

	int i = this->y;
	for (;i<(y+this->y); i++)
	{
		if (is_leap(i)) {
			leap_year_correction++;
		}
	}

	this->y = i;
	add_day(leap_year_correction);
}


