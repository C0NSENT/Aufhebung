//
// Created by consent_ on 01/04/2025.
//

#include <string>
#include <iostream>

class Account
{
public:
	void calculate() {amount += amount * interestRate;}
	static double rate() { return interestRate; }
	static void rate (double);
private:
	double amount;
	std::string owner;
	static double interestRate;
	static double initRate();

	static constexpr int period = 30;
	double daily_tbl[period];
};



void Account::rate (double newRate)
{
	interestRate = newRate;
}

double Account::interestRate = Account::initRate();

int main()
{
	double r;
	r = Account::rate();

	Account ac1;
	Account *ac2 = &ac1;
	r = ac1.rate();
	r = ac2->rate();
}