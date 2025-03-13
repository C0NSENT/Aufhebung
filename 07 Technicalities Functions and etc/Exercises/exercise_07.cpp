//
// Created by consent_ on 09-Mar-25.
//

//Read five names into a vector<string> name,
//then prompt the user for the ages of the people named and store the ages in a vector<double> age.
//Then print out the five (name[i],age[i]) pairs.
//Sort the names (sort(name.begin(),name.end())) and print out the (name[i],age[i]) pairs.
//The tricky part here is to get the age vector in the correct order to match the sorted name vector.
//Hint: Before sorting name, take a copy and use that to make a copy of age in the right order after sorting name

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

//=================================================================================
// Вспомогательные функции
//=================================================================================

template <typename T>
void swap (T& val1, T& val2)
{
	T temp = val1;
	val1 = val2;
	val2 = temp;
}

template <typename T>
bool is_sorted(std::vector<T> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < v[i - 1]) return false;
	}
	return true;
}

int find_index(std::vector<std::string> v, std::string s)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i) == s)
			return i;
	}
}

//=================================================================================
// Основные функции
//=================================================================================

void input_pairs(std::vector<std::string>& v_names, std::vector<double>& v_ages)
{
	std::string name;
	double age;

	while (std::cin >> name >> age)
	{
		if (name == "|")
			break;
		if (age >= 0 && !name.empty() &&
			std::ranges::all_of(name, isalpha))
		{
			v_names.push_back(name);
			v_ages.push_back(age);
		}
		else
			throw std::invalid_argument("Ты даун?");
	}
}

void print_pairs(const std::vector<std::string>& v_names, const std::vector<double>& v_ages)
{
	for (int i = 0; i < v_names.size(); i++)
	{
		std::cout << v_names[i] << " " << v_ages[i] << "\n";
	}
}

void sort_pairs(std::vector<std::string>& v_names, std::vector<double>& v_ages)
{
	std::vector<std::string> v_temp(v_names);
	std::vector<double> v_ages_temp(v_ages);

	std::ranges::sort(v_names);

	/*for (int j = 0; j < v_temp.size(); j++)
	{
		for (int i = 0; i < v_temp.size(); i++)
		{
			if (v_names.at(i) == v_temp.at(j))
			{
				v_ages_temp.push_back(v_ages.at(i));
			}
		}
	}

	v_ages = v_ages_temp;*/

	for (int i = 0; i < v_ages.size(); i++	)
	{
		v_ages.at(i) = v_ages_temp.at(find_index(v_temp, v_names.at(i)));
	}
}

int main()
{
	std::vector <std::string> v_names{"Алексей","Леха", "Мен",
		"Олексій", "Донбасский Джокер"};
	std::vector <double> v_ages{21, 22, 34, 45, 810};

	/*std::vector<std::string> v_names;
	std::vector<double> v_ages;

	input_pairs(v_names, v_ages);*/

	sort_pairs(v_names, v_ages);
	print_pairs(v_names, v_ages);
}