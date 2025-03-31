//
// Created by consent_ on 22-Mar-25.
//



#include <iostream>

class foo
{
public:
	 mutable int a;

	explicit foo(const int& a ) : a(a) {}
	foo(): foo(0) {}
	foo lox() const {return *this;}


	const int& get() const { return this->a; }

	void set(const foo& a)  { this->a = a.a;  }

	int bar() const {return 1;}



	void increment() const {this->a++;}
};

int main()
{
	foo obj1;
	int a = 1;
	obj1.set(a);


	std::cout << obj1.a << std::endl;
}