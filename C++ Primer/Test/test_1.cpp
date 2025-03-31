//
// Created by consent_ on 22-Mar-25.
//



#include <iostream>

class foo
{
public:
	 mutable int a;

	foo lox() const {return *this;}

	foo(const int& a ) : a(a) {}

	const int& get() const { return this->a; }

	int& set()  { this->a; }

	int bar() const {return 1;}

	void increment() const {this->a++;}
};

int main()
{
	foo obj{1};
	//int& a = obj.get();
	/*int* a;
	a{ obj.get()};*/

	obj.increment();

	std::cout << obj.a << std::endl;
}