//
// Created by consent_ on 03-Apr-25.
// 6a7ha3RAD7^^ki4Z

#include <iostream>
#include <string>
#include <vector>
#include <limits>

void print_vector(const std::vector<int>& v)
{
	for (const auto& num: v) {
		std::cout << num << "\n";
	}
}

std::vector<int> input_vector(const std::string& terminator)
{
	std::vector <int> v;
	int num;

	//автоматически выбрасывает ошибку при соотвествующих флагах у потока
	std::cin.exceptions(std::ios::badbit);

	while (true) {
		std::cin >> num;

		if (std::cin) {
			v.push_back(num);
		}
		else if (std::cin.eof()) {
			break;
		}
		else if (std::cin.fail()) {

			if (std::cin.rdstate() & std::ios::failbit) {

				if (std::string s; std::cin >> s && s == terminator ) {
					break;
				}
				std::cerr << "Ожидалось число или буква 'g'\n"
					"Можете продолжать ввод\n";

				std::cin.clear(); //сброс флагов
				//очистка всего потока
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			}
		}

	}
	return v;
}

int main()
{

	std::vector<int> v;

	try {
		v = std::move(input_vector("майнкрафт"));
	}
	catch (const std::ios_base::failure& e) {
		std::cerr << "Здравствуй, жопа, новый год! " << e.what() << "\n";
		return 1;
	}
	print_vector(v);

	return 0;
}