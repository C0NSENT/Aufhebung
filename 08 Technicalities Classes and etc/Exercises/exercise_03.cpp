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

	void is_valid() const
	{
		is_size_valid();
		is_v_names_valid();
		is_v_ages_valid();
	}

	void is_size_valid () const
	{
		if (this->v_names.size() != this->v_ages.size())
			throw std::logic_error("Ошибка: вектора разных размеров");
	}

	void is_v_names_valid() const
	{
		for (const auto& name : this->v_names) {
			if (!std::ranges::all_of(name, isalpha))
				throw std::invalid_argument("Это не имена");
		}
	}
	void is_v_ages_valid() const
	{
		for (const auto& age : this->v_ages) {
			if (!(age > 0 && age < 150))
				throw std::invalid_argument("Люди столько не живут");
		}
	}

	template<typename T>
	void print(const std::vector<T>& v)
	{
		for (const T& val : v ) {std::cout << val << " ";}
		std::cout << "\n";
	}

	//тупо лень креативить вот и написал баббл сорт
	void sort_indices(std::vector<size_t>& v_indices) const
	{
		const size_t size = v_names.size();

		for (size_t i = 0; i < size-1; i++)
		{
			bool swapped = false;
			for (size_t j = 0; j < size-i-1; j++) {
				if (this->v_names.at(v_indices.at(j)) > this->v_names.at(v_indices.at(j+1)) ) {
					std::swap(v_indices.at(j), v_indices.at(j+1));
					swapped = true;
				}
			}
			if (!swapped) return;
		}
	}

	//можно было реализовать через все это через шаблон чтобы не дублировать код
	//но тогда будет потеря в производительности из-за многократного вызова цикла, а так вызывается один
	void apply_ordering(const std::vector<size_t>& v_indices)
	{
		std::vector<std::string> temp_v_names;
		std::vector<double> temp_v_ages;

		for (const auto& index : v_indices) {
			temp_v_names.push_back(v_names.at(index));
			temp_v_ages.push_back(v_ages.at(index));
		}

		v_names = std::move(temp_v_names);
		v_ages = std::move(temp_v_ages);
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
		//print(v_indices);

		sort_indices(v_indices);
		//print(v_indices);

		apply_ordering(v_indices);
		//print(v_indices);
	}

};

int main()
{
	//std::vector<std::string> v_names{"олег", "stepan","gzegoz","sigma", "donbas", "oreshnik", "жопа"};
	std::vector<std::string> v_names = {
		"Андрей",
		"Мария",
		"Сергей",
		"Ольга",
		"Дмитрий",
		"Екатерина",
		"Алексей"
	};
	std::vector<double> v_ages{1, 2, 3, 4, 5, 6, 7};

	/*obj.read_names();
	obj.read_ages();
	obj.sort();*/

	name_pairs obj1{v_names, v_ages};

	obj1.sort();


	std::cout << obj1 << "\n";


}
