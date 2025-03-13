//
// Created by consent_ on 08-Mar-25.
//

/*
void swap_v(int a,int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a,int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_cr(const int& a,const int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}*/

import std;

#include <sec_api/stdio_s.h>

namespace X
{
    int var = 7;
    void print() { printf_s("%i\n", var); }
}

namespace Y {
    int var{0};
    void print(){printf_s("%i\n", var);}
}

namespace Z {
    int var{0};
    void print(){printf_s("%i\n", var);}
}
int main()
{
    X::var = 7;
    X::print();

    using namespace Y;
    var = 9;
    print();
    {
        using Z::var;
        using Z::print;
        var = 11;
        print();
    }
    print();
    X::print();
}