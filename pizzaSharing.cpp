/*Ангел и Борислава си купуват по една пица всеки ден след работа.
Пицарията дава отстъпка от 20% за всяка втора пица.
Ангел изяжда своята пица и 1/3 от пицата на Борислава.
Двамата са се разбрали да споделат разходите за пиците на база какви са им заплатите и колко са изяли от пиците.
Една пица струва 7 лв.
Ангел взима 1800 лв заплата а Борислава 4000 лв заплата.
По колко плащат А и Б
Колко са платили общо в края на седмицата?*/

#include <iostream>
using namespace std;

int main()
{

    double pizzaPrice = 7;
    int days = 7;
    double pizzaPriceDiscount = 7 - (7 * 0.2);
    double overallPizzaPrice = 0;
    int pizzaCount = 0;

    // Калкулиране на цената на пиците за седмицата (за един човек):
    for (int i = 1; i <= days; i++)
    {

        if (i % 2 == 0)
        {
            overallPizzaPrice += pizzaPriceDiscount;
        }
        else
        {
            overallPizzaPrice += pizzaPrice;
        }

        pizzaCount++;
    }

    // Колко са платили общо в края на седмицата:
    double overallPizzaPriceForTwo = overallPizzaPrice * 2;
    cout << "At the end of the week, Borislava and Angel paid a total of BGN " << overallPizzaPriceForTwo << endl;

    // По колко следва да платят за седмицата, ако Ангел изяжда 1/3 от пицата на Борислава:
    double oneThirdOverallPizzaPrice = overallPizzaPrice / 3;
    double overallPizzaPriceForAngel = (overallPizzaPrice + oneThirdOverallPizzaPrice);
    double overallPizzaPriceForBorislava = overallPizzaPrice - oneThirdOverallPizzaPrice;
    cout << "Angel has to pay BGN " << overallPizzaPriceForAngel << endl;
    cout << "Borislava has to pay BGN " << overallPizzaPriceForBorislava << endl;


    //По колко следва да платят за седмицата на база какви са им заплатите, ако Ангел изяжда 1/3 от пицата на Борислава:
    double salaryAngel = 1800;
    double salaryBorislava = 4000;
    // double salaryPercentDiff = salaryAngel / salaryBorislava * 100;
    double paidByAngel = overallPizzaPriceForAngel * (salaryAngel / salaryBorislava);
    double paidByBorislava = overallPizzaPriceForTwo - paidByAngel;
    cout << "Paid by Angel according to salaries:: " << paidByAngel << endl;
    cout << "Paid by Borislava according to salaries:: " << paidByBorislava << endl;

    return 0;
}