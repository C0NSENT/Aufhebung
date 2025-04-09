//
// Created by consent_ on 08-Apr-25.
//

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream inputFile("rust.txt");
	if (inputFile.is_open()) {
		short counter{1};
		for (std::string line; std::getline(inputFile, line);) {
			std::cout << counter++ << "\t│ " << line << std::endl;
		}
	}
}