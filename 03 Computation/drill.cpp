//
// Created by consent_ on 08-Mar-25.
//

#include <iostream>
#include <string>
#include <limits>

void num_comparison(const double& number1, const double& number2)
{
    const  static std::string the_smaller_num_prompt{ "Наименьшее число: " };
    const static std::string the_larger_num_prompt{"Наибольшее число: "};

    if (number1 > number2)
    {
        std::cout << the_smaller_num_prompt << number2 << "\n"
            <<the_larger_num_prompt << number1 << "\n\n";

    }
    else if (number2 > number1)
    {
        std::cout << the_smaller_num_prompt << number1 << "\n"
            << the_larger_num_prompt << number2 << "\n\n";
    }
    else if(static_cast<int> (number1) == static_cast<int>(number2))
    {
        std::cout << "Числа почти равны.\n\n";
    }
    else
    {
        std::cout << "Числа равны.\n\n";
    }
}

void max_min(const double& number, double& min_num, double& max_num)
{
    if (number > max_num)
    {
        max_num = number;
    }
    if (number < min_num)
    {
        min_num = number;
    }

    std::cout << "Наибольшее число: " << max_num << "\n"
        << "Наименьшее число: " << min_num << "\n";
}

int main()
{
    double number;
    double min_num{std::numeric_limits<double>::max()};
    double max_num{std::numeric_limits<double>::lowest()};

    //double number2;

    /*const static std::string prompt{ "Введите два числа:\n" };

    std::cout << prompt;
    while (std::cin>>number1>>number2)
    {
        std::cout << number1 << " " << number2 << "\n\n";

        num_comparison(number1, number2);

        std::cout << prompt;

    } */

    /*std::cout << min_num << "\n"
                << max_num << "\n";*/

    std::cout << "Введите число:\n";

    while (std::cin >> number)
    {
        max_min(number, min_num, max_num);

        std::cout << "Введите число:\n";
    }
}