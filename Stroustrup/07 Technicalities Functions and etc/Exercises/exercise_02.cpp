//
// Created by consent_ on 09-Mar-25.
//



#include <iostream>
#include <string>
#include <vector>
#include <array>


template<typename T>
void print(const std::string& label, const std::vector<T>& v)
{
	std::cout << label << " = [";
	for (int i = 0; i < v.size()-1; i++)
	{
		std::cout << v.at(i) << ", ";
	}
	std::cout << v.at(v.size()-1) << "]" << "\n";
}

template<typename T, std::size_t size>
void print(const std::string& label, const std::array<T, size>& v)
{
	std::cout << label << " = [";
	for (int i = 0; i < size-1; i++)
		std::cout << v.at(i) << ", ";
	std::cout << v.at(size-1) << "]" << "\n";
}

void fibonacci(const int& n_fib1, const int& n_fib2, std::vector<int>& v, const int& size)
{
	v.push_back(n_fib1);
	v.push_back(n_fib2);

	for (int i = 2; i < size; i++)
	{
		v.push_back(v.at(i-1) + v.at(i-2));
		if (v.at(i)<0) break;
	}
}



template<typename T>
std::vector<T> new_reverse(const std::vector<T>& v) //ну тип новый вектор создает
{
	std::vector<T> v_res;

	for (int i = v.size()-1; i >= 0; --i)
		v_res.push_back(v.at(i));

	return v_res;
}

template<typename T>
void old_reverse(std::vector<T>& v)
{
	//ну и кал конечно я написал
	for (std::pair<int, int> iterators(0, v.size()-1);
		iterators.first < iterators.second;
		iterators.first++, iterators.second--)
	{
		T temp = v.at(iterators.first);
		v.at(iterators.first) = v.at(iterators.second);
		v.at(iterators.second) = temp;
	}
}

int main()
{
	/*const std::vector v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	const std::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	print("Циферки ", v);
	print("Циферки", arr);*/

	std::vector<int> v_fib;

	fibonacci(1, 2, v_fib, 10);
	print("",new_reverse(v_fib));

	old_reverse(v_fib);

	print("", v_fib);
	//print<int>("fibonacci", v_fib);

}
