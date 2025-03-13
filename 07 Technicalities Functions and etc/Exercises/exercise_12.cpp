//
// Created by consent_ on 10-Mar-25.
//

// Improve print_until_s() from §7.4.2. Test it.
// What makes a good set of test cases? Give reasons.
// Then, write a print_until_ss() that prints
// until it sees a second occurrence of its quit argument.

#include <iostream>
#include <string>
#include <vector>


void print_until(const std::vector<std::string>& v, const std::string& quit)
{
	if (quit.empty())
		throw std::invalid_argument(quit);

	int counter{0};

	for (const auto& s : v) {
		counter++;
		if (s == quit)

			return;
		std::cout << s << "\n";
	}
}

void print_until_ss(const std::vector<std::string>& v, const std::string& quit)
{
	bool is_second = false;

	for (const auto& s : v) {
		if (!is_second && s == quit)
			is_second = true;

		else if (is_second && s == quit)
			return;

		std::cout << s << "\n";

	}
}


int main()
{
	const std::vector<std::string> v{"aboba", "jopa","zhest", "sosal?", "jopa"};

	//print_until(v, "");
	print_until_ss(v, "jopa");
}