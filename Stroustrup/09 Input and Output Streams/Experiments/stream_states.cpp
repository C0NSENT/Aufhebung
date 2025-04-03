//
// Created by consent_ on 03-Apr-25.
//

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

void foo(std::istream& ist)
{
	std::vector <int> v;
	ist.exceptions(ist.exceptions() | std::ios::badbit);

	while (true) {
		int num;
		ist >> num;

		if (ist) {
			v.push_back(num);
		}
		if (ist.fail()) {
			if (ist.rdstate() & std::ios::failbit) {

				if (char c; ist >> c && c == 'g' ) {
					break;
				} else {
					std::cerr << "Ожидалось число или буква 'g'\n"
						"Можете продолжать ввод\n";
					ist.clear();
					ist.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
			else if (ist.rdstate() & std::ios::badbit) {
				throw std::ios_base::failure("Поток принял ислам");
			}
		}

	}

	print_vector(v);
}

int main()
{
	try {
		foo(std::cin);
	}
	catch (std::ios_base::failure& e) {
		std::cerr << "Здравствуй, жопа, новый год! " << e.what() << "\n";
		return 1;
	}

}