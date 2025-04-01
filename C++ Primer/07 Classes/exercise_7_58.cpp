//
// Created by consent_ on 01/04/2025.
//

#include <vector>

class Example
{
public:
	static double rate = 6.5;
	static const int vecSize = 20;
	static std::vector<double> vec(vecSize);

};

double Example::rate;
std::vector<double> Example::vec;