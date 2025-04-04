//
// Created by consent_ on 04-Apr-25.
//

#include <iostream>
#include <iomanip>


int main()
{
	constexpr double num = 1234567.89;
	std::cout <<
			"┌───────────────────┬──────────────────────────┐\n"
			"│ iomanip           │ representation           │\n"
			"├───────────────────┼──────────────────────────┤\n";
	std::cout << std::left
			<< std::setw(13) <<"│ std::defaultfloat │ "
			<< std::setw(25) <<std::defaultfloat << num << "│\n"
			<< std::setw(13) <<"│ std::fixed        │ "
			<< std::setw(25) <<std::fixed << num << "│\n"
			<< std::setw(13) <<"│ std::scientific   │ "
			<< std::setw(25) <<std::scientific << num << "│\n";
	std::cout <<
			"└───────────────────┴──────────────────────────┘\n";
}