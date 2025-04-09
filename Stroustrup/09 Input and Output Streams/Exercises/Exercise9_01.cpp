//
// Created by consent_ on 08-Apr-25.
//

#include <iostream>
#include <fstream>

#include <string>

int main()
{
	const std::string file_path{"exercises9_01.txt"};
	std::ifstream file(file_path);

	if (!file.is_open()) {
		std::cerr << "Error opening file \n" << "File path: " << file_path << std::endl;
		return -1;
	}
	const std::string ofile_path{"The Grapes of Wrath.txt"};
	std::ofstream file_ofile(ofile_path);

	for (std::string line; std::getline(file, line );) {
		for (char& c : line) {
			c = std::tolower(c);
		}
		file_ofile << line << std::endl;
	}
}
