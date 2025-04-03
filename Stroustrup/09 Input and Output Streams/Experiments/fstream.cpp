//
// Created by consent_ on 03-Apr-25.
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

auto file_read(const std::string& file_name) -> std::vector<std::string>
{
	if (std::ifstream input_file(file_name); input_file.is_open()) {
		std::string line;
		std::vector<std::string> result;

		while (std::getline(input_file, line)) {
			result.push_back(line);
		}
		return result;
	}
	throw std::runtime_error("File could not be opened");
}

void file_write(const std::string& file_name, const std::vector<std::string>& vec)
{
	std::ofstream output_file(file_name);

	output_file << "# Архитектурные Стили\n";

 	if (output_file.is_open()) {

		int counter{0};

		for (const auto& s : vec) {
			output_file << (++counter) << ". " << s << "\n";
		}
		output_file.close();

		std::cout << "Success\n";

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
	const std::string output_file_name("output.md");

	try {
		const std::vector vec{file_read(file_name)};
		file_write(output_file_name, vec);
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Error: " <<e.what() << std::endl;
		return 1;
	}

	return 0;
}