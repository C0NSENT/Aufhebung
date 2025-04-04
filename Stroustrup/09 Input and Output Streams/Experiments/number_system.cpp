//
// Created by consent_ on 04-Apr-25.
//

#include <iostream>

int main()
{
	const int num{1234};

	std::cout << num << '\n' <<
		std::hex << num << '\n' <<
			std::oct << num << '\n';
}