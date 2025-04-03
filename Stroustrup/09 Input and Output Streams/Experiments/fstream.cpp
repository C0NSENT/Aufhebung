//
// Created by consent_ on 03-Apr-25.
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

auto file_handler(const std::string& file_name) -> std::vector<std::string>
{
	if (std::ifstream input_file(file_name); input_file.is_open()) {
		std::string line;
		std::vector<std::string> result;

		while (std::getline(input_file, line)) {
			result.push_back(line);
		}
		input_file.close();
		return result;
	}
	throw std::runtime_error("File could not be opened");
}

void file_read(const std::string& file_name, std::vector<std::string>& vec)
{
	std::ofstream output_file(file_name, std::ios::out);

	if (output_file.is_open()) {

		int counter{0};

		for (const auto& s : vec) {
			output_file << (++counter) << ". " << s << "\n";
		}
		output_file.close();
		return;
	}
	throw std::runtime_error("File could not be opened");
}

void print_vector(const std::vector<std::string>& vec)
{
	for (const auto& s : vec) {
		std::cout << s << "\n";
	}
}


int main()
{
	const std::string file_name("architecture styles.txt");
	const std::string output_file_name("output.txt");

	std::vector<std::string> vec{file_handler(file_name)};

	file_read(output_file_name, vec);

	//print_vector(vec);

}