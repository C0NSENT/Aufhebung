//
// Created by consent_ on 08-Mar-25.
//

/*
Use the example above as a model for a program that converts yen ('y'), kroner ('k'), and pounds ('p') into dollars.
If you like realism, you can find conversion rates on the Web.

пишу код на c почему и нет
 */

#include <stdio.h>

void currency_converter(const char currency, const double money)
{
    const static double nok_per_usd = 11.7; //курс норвежской кроны к доллару
    const static double jpy_per_usd = 150.91; //курс йены
    const static double gbp_per_usd = 0.79; //курс фунта стерлинга

    double dollars;

    switch (currency)
    {
        case('y'):
            dollars = money / jpy_per_usd;
        printf_s("%lf yen (JPY) = %lf dollars (USD)", money, dollars);
        break;

        case('k'):
            dollars = money / nok_per_usd;
        printf_s("%lf kroner (JPY) = %lf dollars (USD)", money, dollars);
        break;

        case('p'):
            dollars = money / gbp_per_usd;
        printf_s("%lf pounds (GBP) = %lf dollars (USD)", money, dollars);
        break;

        default:
            printf_s("Sorry but %c not found", currency);
    }
}

int main()
{
    double money;
    char currency;

    //printf_s безопасная версия обычного printf
    printf_s("Please specify a currency:\n"
        "y - Yen (JPY)\n"
        "k - Kroner (NOK)\n"
        "p - Pound (GBP)\n");

    scanf_s("%c", &currency); //scanf_s вроде как более безопасная версия обычного scanf

    printf_s("Please type amount of money:\n ");
    scanf_s("%lf", &money);

    currency_converter(currency, money);

    return 0;
}