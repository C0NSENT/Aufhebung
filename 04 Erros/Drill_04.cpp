//
// Created by consent_ on 08-Mar-25.
//

#include <iostream>
#include <vector>
#include <string>

int main()
{
    try
    {
        std::string
        return 0;
    }
    catch (std::exception& e)
    {
        std::cerr << "error:" << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "Oops:unknown exception\n";
        return 2;
    }
}