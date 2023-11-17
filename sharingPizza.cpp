/*Ангел и Борислава си купуват по една пица всеки ден след работа.
Пицарията дава отстъпка от 20% за всяка втора пица.
Ангел изяжда своята пица и 1/3 от пицата на Борислава.
Двамата са се разбрали да споделат разходите за пиците на база какви са им заплатите и колко са изяли от пиците.
Една пица струва 7 лв.
Ангел взима 1800 лв заплата а Борислава 4000 лв заплата.
По колко плащат Ангел и Борислава?
Колко са платили общо в края на седмицата?*/

#include <iostream>
using namespace std;

int main()
{
    
    int days = 5; // работна седмицата
    double pizzaPrice = 7;
    double pizzaPriceDiscount = 7 - (7 * 0.2);
    double totalPizzaPrice = days * (pizzaPrice + pizzaPriceDiscount);

    cout << "The total cost of the pizza is " << totalPizzaPrice << endl;

    // По колко следва да платят за седмицата, ако Ангел изяжда 1/3 от пицата на Борислава:
    double halfPrice = totalPizzaPrice / 2;
    double oneThirdOverallPizzaPrice = halfPrice / 3;
    double totalPizzaPriceForAngel = halfPrice + oneThirdOverallPizzaPrice;
    double totalPizzaPriceForBorislava = halfPrice-oneThirdOverallPizzaPrice;
    cout << "Angel has to pay BGN " << totalPizzaPriceForAngel << endl;
    cout << "Borislava has to pay BGN " << totalPizzaPriceForBorislava << endl;

    // По колко следва да платят за седмицата на база какви са им заплатите, ако Ангел изяжда 1/3 от пицата на Борислава:
    double salaryAngel = 1800;
    double salaryBorislava = 4000;
    // double salaryPercentDiff = salaryAngel / salaryBorislava * 100;
    double paidByAngel = totalPizzaPriceForAngel * (salaryAngel / salaryBorislava);
    double paidByBorislava = totalPizzaPrice - paidByAngel;
    cout << "Paid by Angel according to salaries: " << paidByAngel << endl;
    cout << "Paid by Borislava according to salaries: " << paidByBorislava << endl;

    return 0;
}