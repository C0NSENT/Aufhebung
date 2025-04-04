//
// Created by consent_ on 04-Apr-25.
//

#include <iomanip>
#include <iostream>
#include <sstream>
#include <random>

int random_number(const int min, const int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);
	return dis(gen);
}

int main()
{
	std::ostringstream os;
	for (int i = 1; i <= 10; i++) {

		int num = random_number(1, 999999);
		os << "myfile" << std::setw(6) << std::setfill('0') << num << ".suddamhussein" << std::endl;
		std::cout << os.str() << std::endl;
		os.str(""); //очистка строки
	}
	std::cout << os.str() << std::endl;
}