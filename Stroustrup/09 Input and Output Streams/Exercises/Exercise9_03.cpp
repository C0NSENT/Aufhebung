//
// Created by consent_ on 09-Apr-25.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string disevowel(const std::string& str)
{
	std::string result{};
	for (auto& ch : str) {
		switch (ch) {
			case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
			case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y':
				continue;
			default:
				result.push_back(ch);
		}
	}
	std::cout << result << std::endl;
	return result;
}

int main()
{
	const std::string file_name{"Mr. Self Destruct.txt"};

	std::ifstream inputFile(file_name);
	if (!inputFile.is_open()) {
		std::cerr << "Error opening input file" << std::endl;
		return 1;
	}

	std::stringstream ss;
	ss << inputFile.rdbuf();

	std::ofstream outputFile(file_name);
	if (!outputFile.is_open()) {
		std::cerr << "Error opening output file" << std::endl;
		return 1;
	}
	for (std::string line; std::getline(ss, line);) {
		std::cout << line << '\n';
		line = disevowel(line);
		std::cout << line << '\n';
		outputFile << line << std::endl;
	}

}