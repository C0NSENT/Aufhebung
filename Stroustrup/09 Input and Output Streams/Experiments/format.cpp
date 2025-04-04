//
// Created by consent_ on 04-Apr-25.
//

#include <iostream>
#include <string>

int main()
{
	/*constexpr  int val = 1234;
	const std::string s = std::format("Hello {}\n", val);
	std::cout << s << std::endl;*/

	constexpr double d = 124.44732;
	std::cout << std::format(" {:12} - {:12.8f} - {:30.20e}", d, d, d);
}