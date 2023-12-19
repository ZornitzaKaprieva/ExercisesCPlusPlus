#include <iostream>
#include <cmath>
using namespace std;

class Calculator
{
public:
    Calculator(double _num1, char _operation)
    {
        this->num1 = _num1;
        this->operation = _operation;
    }

    Calculator(double _num1, char _operation, double _num2)
    {
        this->num1 = _num1;
        this->operation = _operation;
        this->num2 = _num2;
    }

protected:
    double num1;
    double num2;
    char operation;
};

class Calculator1Num : public Calculator
{
public:
    Calculator1Num(double _num1, char _operation) : Calculator(_num1, _operation)
    {
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

    void oneNumOperation()
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
};

class Calculator2Num : public Calculator
{
public:
    Calculator2Num(double _num1, char _operation, double _num2) : Calculator(_num1, _operation, _num2)
    {
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

    void twoNumOperation()
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
};

int main()
{
    // Calculator calculator1Num(1, '!'); //ok
    // Calculator calculator2Num(1, '+', 3); //ok

    Calculator1Num calc1(2, '!');
    Calculator2Num calc2(12, '+', 23);

    // calc1.printFactorial(5); //ok
    // calc2.printAddition(3, 7); //ok

    // calc1.oneNumOperation(); //ok
    // calc2.twoNumOperation(); //ok

    // Redirection:
    while (true)
    {
        int countNums;
        double num1, num2;

        do
        {
            cout << "Operation with 1 or 2 numbers: ";
            cin >> countNums;
        } while (countNums != 1 && countNums != 2);

        countNums == 1 ? calc1.oneNumOperation() : calc2.twoNumOperation();
    }

    return 0;
}
