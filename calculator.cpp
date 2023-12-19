#include <iostream>
#include <cmath>
using namespace std;

void printRedirection();

int factorial(double x);
void printFactorial(int factorial); // !
void printSqrt(double x);        // s
void oneNumOperation(double num1, char operation);

void printAddition(double x, double y);       // +
void printSubtraction(double x, double y);    // -
void printMultiplication(double x, double y); // *
void printDivision(double x, double y);       // /
void printModulo(double x, double y);            // %
void printPow(double x, double y);            // p 
void twoNumOperation(double num1, char operation, double num2);

int main()
{

printRedirection(); //todo: Ако се въведе char вместо int, програмата бъгва!
   
    return 0;
}

void printRedirection()
{
while (true)
    {

        int countNums;
        double num1, num2;

        do
        {
            cout << "Operation with 1 or 2 numbers: ";
            cin >> countNums; 
        } 
        while (countNums != 1 && countNums != 2);

        countNums == 1 ? oneNumOperation(num1, 'o') : twoNumOperation(num1, 'o', num2);
    }
}

int factorial(double x)
{
    if (x == 1)
    {
        return x;
    }

    return x * factorial(x - 1);
}

void printFactorial(int x)
{
    x = (int)x;
    cout << x << "! = " << factorial(x) << endl;
}

void printSqrt(double x)
{
    cout << "The square root of " << x << " = " << sqrt(x) << endl; // √
}

void oneNumOperation(double num1, char operation)
{
    cout << "Enter number and operator: " << endl;
    cin >> num1 >> operation;
    cout << num1 << operation << endl;
    system("cls");

    switch (operation)
    {
    case '!':
        printFactorial(num1);
        break;
    case 's':
        printSqrt(num1);
        break;
    default:
        cout << "Invalid input" << endl;
        break;
    }
}

void printAddition(double x, double y)
{
    cout << x << " + " << y << " = " << x + y << endl;
}

void printSubtraction(double x, double y)
{
    cout << x << " - " << y << " = " << x - y << endl;
}

void printMultiplication(double x, double y)
{
    cout << x << " * " << y << " = " << x * y << endl;
}

void printDivision(double x, double y)
{
    cout << x << " / " << y << " = " << x / y << endl;
}

void printModulo(double x, double y)
{
    bool isNum1Int, isNum2Int;
    isNum1Int = (int)x == x;
    isNum2Int = (int)y == y;

    if (isNum1Int && isNum2Int)
    {
        cout << x << " "
             << "%"
             << " " << y << " = " << (int)x % (int)y << endl;
    }
    else
    {
        cout << "Not valid" << endl;
    }
}

void printPow(double x, double y)
{
    cout << x << " power " << y << " = " << pow(x, y) << endl;
}

void twoNumOperation(double num1, char operation, double num2)
{
    cout << "Enter 1st number, operator and 2nd number:" << endl;
    cin >> num1 >> operation >> num2;

    system("cls");

    switch (operation)
    {
    case '+':
        printAddition(num1, num2);
        break;
    case '-':
        printSubtraction(num1, num2);
        break;
    case '*':
        printMultiplication(num1, num2);
        break;
    case '/':
        printDivision(num1, num2);
        break;
    case '%':
        printModulo(num1, num2);
        break;
    case 'p':
        printPow(num1, num2);
        break;
    default:
        cout << "Invalid input" << endl;
        break;
    }
}