//
// Created by consent_ on 10-Mar-25.
//

// Write a function that takes a vector<string> argument and
// returns a vector<int> containing the number of characters in each string.
// Also find the longest and the shortest string and the lexicographically first and last string.
// How many separate functions would you use for these tasks? Why?

#include <iostream>
#include <string>
#include <vector>

std::vector<int> count_chars(const std::vector<std::string>& v_strings)
{
	std::vector<int> count_chars;
	for (auto s : v_strings)
		count_chars.push_back(s.length());

	return count_chars;
}

int main()
{
	std::vector<std::string> v_strings{"Aboba","jopa", "pohuy", "pizdec"};

	std::vector<int> v_chars_count(count_chars(v_strings));

	for (int val : v_chars_count) {
		std::cout << val << "\n";
	}
}