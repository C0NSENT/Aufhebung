//
// Created by consent_ on 11-Mar-25.
//


#include <chrono>
#include <iostream>
#include <array>
#include <string>



enum class month
{
	jan = 1, feb, mar, apr, may, jun,
	jul, aug, sep, oct, nov, dec
};

static int to_int(const month& m) {return static_cast<int>(m);}

static const std::array<std::string, 13> month_names = {"not a month", "January", "February", "March",
												"April", "May", "June",
												"July", "August", "September",
												"October", "November", "December"};

std::ostream& operator<<(std::ostream& os, const month& m)
{
	return os << month_names.at(to_int(m));
}





month operator++(month& m)
{
	//если месяц декабрь то выдает январь, если какой-либо другой то просто инкременирует
	m = (m == month::dec) ? month::jan : month{to_int(m)+1};
	return m;
}

int main()
{
	month m{12};


	++m;
	std::cout << m << std::endl;
}


