//
// Created by consent_ on 08-Mar-25.
//

/*
Change the program to output the two lines
Hello, programming!
Here we go!

Прога, которая выводит разноцветный текст на экран
*/

#include <iostream>



enum text_color
{
    none = 0,
    black = 30,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white
};


void set_color( const text_color& color)
{
    std::cout << "\033[" << color << "m";
}

int main()
{
    set_color(text_color::green);
    std::cout << "Hello, programming!\n" <<
        "Here we go!\n";

    set_color(text_color::none);
    std::cout << "\nFoo" << std::endl;

    return 0;
}

