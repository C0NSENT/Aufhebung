//
// Created by consent_ on 04-Apr-25.
//

#include <iostream>

void output_birth_year(const int birth_year)
{
	std::cout << "В десятичной системе:\t\t\t" <<birth_year
			<< "\nВ шестнадцатиричной системе:\t" << std::hex << birth_year
			<< "\nВ восьмиричной системе:\t\t\t" << std::oct << birth_year;
}

int main()
{
	int a, b , c, d;
	std::cin >> a >> std::oct >> b >> std::hex >> c >> d;
	std::cout << a  << '\t' << b << '\t' << c << '\t' << d << '\n';
}
