//
// Created by consent_ on 07-Apr-25.
//

#include <iostream>

class FALLOUT_NEW_VEGAS
{
	std::string FNV;
public:
	FALLOUT_NEW_VEGAS() : FNV{"GOOOOOOOOOOOOOL"} {}

	void print() {
		std::cout << FNV << std::endl;
	}
};

int main ()
{
	FALLOUT_NEW_VEGAS AUE;
	AUE.print();
}