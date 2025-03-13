//
// Created by consent_ on 11-Mar-25.
//

#include "date.h"


//===========================ОПЕРАТОРЫ================================

month date::operator++(month& m)
{
	m = (m==month::dec) ? month::jan : month{to_int(m)+1};
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

date& date::operator++(date &obj, int)
{
	if (obj.d==days_in_month(obj.m,obj.y))
	{
		obj.d = 1;
	}

	return obj;
}


date& date::operator=(const date& obj)
= default;

std::ostream& operator<<(std::ostream& os, const date& obj)
{
	os << obj.y <<" "<< obj.m <<" "<<obj.d;
	return os;
}

//===========================ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ================================


bool date::is_valid(const int& y, const month& m, const int& d)
{
	if (m == month::feb)
	{
		if (is_leap(y) && d == 29) return false;
	}

	if (d >  days_in_month(m, y)) return false;

	return true;
}

bool date::is_leap(const int &y) {
		return (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0));
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

date::date(const int &y, const month &m, const int &d)
{
	if (!is_valid(y, m, d))
		throw std::invalid_argument("Ваша дата - инвалид, соболезнуем");

	this->y = y;
	this->m = m;
	this->d = d;
}

date::date(const month &m, const int &d, const int &y):date(y, m, d){}

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

	add_day(m);
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

int main()
{
	date date1{2020, month::dec, 22};

	date1.add_year(4);

	std::cout << date1 << "\n";
}

