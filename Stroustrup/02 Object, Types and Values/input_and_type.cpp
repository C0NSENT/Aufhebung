//
// Created by consent_ on 08-Mar-25.
//

#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
    std::cout << "Please enter your first name and age\n";

    std::string first_name = "???";

    int age = -1;

    std::cin >> first_name >> age;

    std::cout << "Hello, " << first_name <<
        "(age " << age << ")\n";
}