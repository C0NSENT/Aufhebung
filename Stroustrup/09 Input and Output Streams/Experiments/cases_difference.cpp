//
// Created by consent_ on 04-Apr-25.
//

#include <iostream>
#include <string>

int main()
{
	std::string input;
	std::getline(std::cin, input);

	for (char& ch : input) {
		if (islower(ch))
			ch = toupper(ch);

		else if (isupper(ch))
			ch = tolower(ch);

	}
	std::cout << input << std::endl;
}