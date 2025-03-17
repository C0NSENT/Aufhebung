//
// Created by consent_ on 11-Mar-25.
//

#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

enum class month
{
	jan = 1, feb, mar, apr, may, jun,
	jul, aug, sep, oct, nov, dec
};

month operator++(month& m);


class date
{
	//============================СТРУКТУРА КЛАССА===================================

	int y;
	month m;
	int d;

//===========================ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ================================


	bool is_valid(const int& y, const month& m, const int& d);


	bool is_leap(const int& y);

	int to_int(const month& m){return static_cast<int>(m);}
	month to_month(const int& num);

	int days_in_year(const int& y);
	int days_in_month(const month& m, const  int& y);

	date str_to_date(const std::string& str_date);

	//зачем мне ее писать если is_valid
	//bool is_str_valid(const std::array<std::string, 3>& str_date);
	//ладно она нужна
	//bool is_arr_date_valid(const std::array<int,3>& arr_date);

	int date_to_days(const date& date);
	int date_to_days(const date& date, const int& base_year);


	date days_to_date(const int& days);
	date days_to_date( int days, const int& base_year);

public:

	//===========================КОНСТРУКТОРЫ================================

	date();
	date(const std::string& s);
	date(const int& y, const month& m, const int& d );
	date(const month& m, const int& d, const int& y);
	date(const date& date);
	//если тебе нечего делать можешь еще конструкторы понаписать

	~date()=default;

	//===========================ИНТЕРФЕЙС================================

	void add_day(const int& d);
	void add_month(const int& m);
	void add_year(const int& y);

	void take_day(const int& d);
	void take_month(const int& m);
	void take_year(const int& y);


	//===========================ОПЕРАТОРЫ================================

	friend std::ostream& operator<<(std::ostream& os, const month& obj);

	date& operator++(int)
	{
		/*if (this->d==days_in_month(this->m, this->y))
		{
			this->d = 1;
		}
		else this->d++;*/

		//this->d = (this->d==days_in_month(this->m, this->y)) ? 1 : this->d+1;

		//Совсем забыл про год проще просто функция add_day() вызвать

		add_day(1);

		return *this;
	}


	date& operator=(const date& obj);


	friend std::ostream& operator<<(std::ostream& os, const date& obj);

};

#endif //DATE_H