//
// Created by consent_ on 22-Mar-25.
//

#include <iostream>

class foo
{
	int a;
	public:
	foo(const int& a ) : a(a) {}

	const int& get() const { return this->a; }
	int bar() const {return 1;}
};

int main()
{
	foo obj{1};
	//int& a = obj.get();
	/*int* a;
	a{ obj.get()};*/

	obj.bar();

	std::cout << obj.get() << std::endl;
}