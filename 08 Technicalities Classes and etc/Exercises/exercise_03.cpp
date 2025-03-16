//
// Created by consent_ on 14-Mar-25.
//

//Replace Name_pair::print() with a (global) operator << and define == and != for Name_pairs.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>
#include <stdexcept>
#include <numeric>


class name_pairs
{
	//======================СВОЙСТВА КЛАСС===========================
	std::vector<std::string> v_names;
	std::vector<double> v_ages;

	//======================ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ===========================

	void is_valid () const
	{
		if (this->v_names.size() != this->v_ages.size())
			throw std::logic_error("Ошибка: вектора разных размеров");
	}

	std::string get_index(size_t i )
	{
		return this->v_names.at(i);
	}

	void apply_ordering(const std::vector<size_t>& indeces)
	{

	}

	public:
	//======================ОПЕРАТОРЫ===========================

	name_pairs& operator=(const name_pairs& obj) = default;

	[[nodiscard]] bool operator==(const name_pairs& obj) const
	{
		return std::tie(v_names, v_ages) == std::tie(obj.v_names, obj.v_ages);
	}

	bool operator!=(const name_pairs& obj) const
	{
		return !(this->operator==(obj));
	}

	friend std::ostream& operator<<(std::ostream& os, const name_pairs& obj)
	{
		for (int i = 0; i < obj.v_names.size(); i++)
			os << "(" << obj.v_names.at(i) << ", " << obj.v_ages.at(i) << ")\n";

		return os;
	}
	//======================КОНСТРУКТОРЫ===========================

	name_pairs() = default;

	name_pairs(const std::vector<std::string>& v_names, const std::vector<double>& v_ages)
	: v_names(v_names), v_ages(v_ages)
	{
		is_valid();
	}

	name_pairs(const name_pairs& obj) = default;

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
			std::cout << "Введите имя человека по имени " << name << " - ";
			std::cin >> input_age;
			if (input_age > 0 && input_age < 150)
				this->v_ages.push_back(input_age);
			else
				throw std::invalid_argument("Люди столько не живут...");
		}
	}

	void sort()
	{
		std::vector<size_t> v_indices(this->v_names.size());
		//функция заполняет вектор числами, ну чо удобно
		std::iota(v_indices.begin(), v_indices.end(), 0);

		/*std::ranges::sort(v_indices, {}, [this](const size_t& i){
			return this->v_names.at(i);
		});*/
		std::ranges::sort(v_indices, {}, get_index());


	}

};

int main()
{
	name_pairs obj;

	std::vector<std::string> v_names{"олег", "stepan","gzegoz","sigma", "donbas", "oreshnik"};
	std::vector<double> v_ages{1, 2, 3, 4, 5, 6};

	/*obj.read_names();
	obj.read_ages();
	obj.sort();*/

	name_pairs obj1{v_names, v_ages};



	//std::cout << obj1 << std::endl;


}
