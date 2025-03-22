//
// Created by consent_ on 08-Mar-25.
//

/*
 Add a unit to each double entered; that is, enter values such as 10cm, 2.5in, 5ft, or 3.33m. Accept the four units: cm, m, in, ft.
 Assume conversion factors 1m==100cm, 1in==2.54cm, 1ft==12in.
 Read the unit indicator into a string. You may consider 12 m (with a space between the number and the unit) equivalent to 12m (without a space)

Написать алгоритм сортировки
*/

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <vector>
#include <random>

struct length
{
	std::string str_num;
	std::string measure_type;
};

length separate(const std::string& input)
{
	length out;

	for (const char c : input)
	{
		if (std::isdigit(c) || (c == '.') || (c == '-')) out.str_num.push_back(c);
		else if (std::isalpha(c)) out.measure_type.push_back(c); //бинарная функция, которая проверяет является ли char буквенным символом
	}
	return out;
}

void max_min(const double& number, double& max_num, double& min_num)
{


	if (number > max_num) max_num = number;
	if (number < min_num) min_num = number;
}

bool is_type_valid(const std::string& measure_type)
{
	const static std::string valid_types[]{ "cm","m","in", "ft" };

	bool is_valid = false;

	for (const std::string& type : valid_types)
	{
		if (measure_type == type) is_valid = true;

	}

	return is_valid;
}

double convert_to_cm(const std::string& str_num, const std::string& measure_type)
{
	static constexpr double meter_conversion = 100.0;
	static constexpr double inch_conversion = 2.54;
	static constexpr double foot_conversion = 12 * inch_conversion;

	const double converted_num = std::stod(str_num);

	if (measure_type == "m") return (converted_num * meter_conversion);
	if (measure_type == "in") return (converted_num * inch_conversion);
	if (measure_type == "ft") return (converted_num * foot_conversion);

	return(converted_num);
}

double convert_to_m(const std::string& str_num, const std::string& measure_type)
{
	static constexpr double cm_conversion = 0.001;
	static constexpr  double in_conversion = 0.0254;
	static constexpr double ft_conversion = 0.3048;

	const double converted_num = std::stod(str_num);

	if (measure_type == "cm") return (converted_num * cm_conversion);
	if (measure_type == "in") return (converted_num * in_conversion);
	if (measure_type == "ft") return (converted_num * ft_conversion);

	return (converted_num);
}

std::string meter_word_ending(const double& num)
{
	const char last = std::to_string(num).back();

	switch (last)
	{
		case 1:
			return "метр";
		case 2: case 3: case 4:
			return "метра";

		default:
			return "метров";
	}
}

template <typename T>
void print_vector(const std::vector<T>& vector)
{
	std::cout << "[ ";
	for (int i = 0; i < vector.size()-1; i++)
	{
		std::cout << vector.at(i) << ", ";
	}
	std::cout << vector.at(vector.size()-1) << " ]\n";
}

//меняет местами две переменные
template<typename T>
void swap(T& val1, T& val2)
{
	T temp = val1;
	val1 = val2;
	val2 = temp;
}

template <typename T>
std::vector<T> stooge_sort(std::vector<T> in_vector)
{
	return in_vector;
}

//random bullshit go
template<typename T>
std::vector<T> bogosort(std::vector<T> in_vector)
{
	std::random_device key;
	std::mt19937_64 gen(key());
	std::uniform_int_distribution<> range(0, in_vector.size() - 1);

	bool is_sorted{false};

	int counter{0};

	do
	{
		swap(in_vector.at(range(gen)), in_vector.at(range(gen)));

		//проверка отсортированности массива
		for (int i = 1; i < in_vector.size(); i++)
		{
			if (in_vector.at(i - 1) < in_vector.at(i))
			{
				is_sorted = true;
			}
			else
			{
				is_sorted = false;
				break;
			}
		}

		counter++;

	} while (!is_sorted);

	std::cout << counter << "\n";

	return in_vector;
}

int main()
{
	double max_num{ std::numeric_limits<double>::lowest() };
	double min_num{ std::numeric_limits<double>::max() };
	std::string in_str;

	double sum_num{0};
	int counter{ 0 };
	std::vector<double> converted_vector{};


	while (std::cin >> in_str)
	{
		if (in_str == "|") break;

		auto [str_num, measure_type] = separate(in_str); //инициализация структуры (оказывается так можно)

		if (is_type_valid(measure_type))
		{
			std::cout << str_num << " " << measure_type << "\n";

			double converted_num = convert_to_m(str_num, measure_type);

			converted_vector.push_back(converted_num);


			sum_num += converted_num;
			counter++;

			max_min(converted_num, max_num, min_num);
		}
		else
		{
			std::cout << "Числа не будет оно приняло ислам\n";
		}
	}

	converted_vector = bogosort(converted_vector);

	std::cout << "Наибольшее число: " << max_num << meter_word_ending(max_num) <<".\n"
		<< "Наименьшее число: " << min_num << meter_word_ending(min_num) << ".\n"
		<< "Сумма чисел: " << (sum_num / 100) << " " << meter_word_ending(sum_num) <<"."<< "\n"
		<< "Всего чисел было введено: " << counter << ".\n";

	print_vector(converted_vector);
}