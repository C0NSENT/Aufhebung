//
// Created by consent_ on 01/04/2025.
//

#include "Archiver.h"

int main()
{
	std::string file_path;
	std::cout << "Enter file archive path: \n";
	std::cin >> file_path;



	if (file_path == "1")
		file_path="D:\\Open this folder only if you are listening Skinny Puppy rn\\C++\\Aufhebung\\Mini Projects\\Archiver\\cmake-build-debug\\jopa.txt";


	std::ifstream file(file_path);

	if (!file.is_open()) {
		throw std::invalid_argument("File could not be opened: " + file_path);
	}


}