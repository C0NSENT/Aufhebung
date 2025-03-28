//
// Created by consent_ on 14-Mar-25.
//

//Design and implement a Name_pairs class holding (name,age) pairs where name is a string and age is a double.
//Represent that as a vector<string> (called name) and a vector<double> (called age) member.
//Provide an input operation read_names() that reads a series of names.
//Provide a read_ages() operation that prompts the user for an age for each name.
//Provide a print() operation that prints out the (name[i],age[i]) pairs (one per line) in the order determined by the name vector.
//Provide a sort() operation that sorts the name vector in alphabetical order and reorganizes the age vector to match.
//Implement all ‘‘operations’’ as member functions. Test the class (of course: test early and often

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class name_pairs
{
	//======================СВОЙСТВА КЛАСС===========================
	std::vector<std::string> v_names;
	std::vector<double> v_ages;

	//======================ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ===========================

	bool is_size_valid()
	{
		//не забудь реализовать
	}

	public:
	//======================ОПЕРАТОРЫ===========================

	name_pairs& operator=(const name_pairs& obj) = default;

	friend std::ostream& operator<<(std::ostream& os, const name_pairs& obj)
	{
		for (int i = 0; i < obj.v_names.size(); i++)
			os << "(" << obj.v_names.at(i) << ", " << obj.v_ages.at(i) << ")\n";

		return os;
	}
	//======================КОНСТРУКТОРЫ===========================

	name_pairs() = default;

	name_pairs(const std::vector<std::string>& v_names, const std::vector<double>& v_ages)
	{
		this->v_names = v_names;
		this->v_ages = v_ages;
	}

	name_pairs(const name_pairs &obj) = default;

	void read_names()
	{
		std::string input_str;

		while (std::cin >> input_str) {
			if (std::ranges::all_of(input_str, isalpha)) {
				this->v_names.push_back(input_str);
			}
			// отсылка на тот анекдот где супермен в темноте отпердолил бетмена
			else if (input_str == "|" || input_str == "i am batman") {
				return;
			}
			else {
				throw std::invalid_argument("Ты чо напечатал, шиз?");
			}
		}
	}

	void read_ages()
	{
		double input_age;

		for (const std::string& name : this->v_names) {
			std::cout << "Введите имя человека по имени " <<name << " - ";
			std::cin >> input_age;
			if (input_age < 0 || input_age < 150)
				this->v_ages.push_back(input_age);
			else
				throw std::invalid_argument("Люди столько не живут...");
		}
	}

	void sort()
	{
		const std::vector<std::string> temp_names = this->v_names;
		std::vector<double> temp_ages;
		std::ranges::sort(this->v_names);

		for (int i = 0; i < this->v_names.size(); i++) {
			for (const auto & v_name : this->v_names) {
				if (temp_names.at(i) == v_name) {
					temp_ages.push_back(this->v_ages.at(i));
				}
			}
		}

		this->v_ages = temp_ages;
	}

};

int main()
{
	name_pairs obj;

	std::vector<std::string> v_names{"oleg", "stepan","gzegoz","sigma", "donbas", "oreshnik"};
	std::vector<double> v_ages{1, 2, 3, 4, 5, 6};

	/*obj.read_names();
	obj.read_ages();
	obj.sort();*/

	name_pairs obj1{v_names, v_ages};

	obj1.sort();

	std::cout << obj1 << std::endl;
}
