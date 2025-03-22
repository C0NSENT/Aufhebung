//
// Created by consent_ on 08-Mar-25.
//

#include <iostream>
#include <string>
#include  <Windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::cout << "Введи свое имя:\n ";

    //Строка в кодировке Юникода, правда кал полнейший, т.к. с тем же потоком ввода-вывода толком не работает
    const std::u8string first_name{u8"ваджло"};


    //std::cin >> reinterpret_cast<const char*>(first_name.c_str());

    std::cout << "Привет, " << reinterpret_cast<const char*>(first_name.c_str()) << "!\n";

    //std::cout << "АБАВ";

    printf("АБВ");

}

