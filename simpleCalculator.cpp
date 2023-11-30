#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float num1, num2;
    char operation = '%';
    cout << "Enter 1st number, operator and 2nd number:" << endl;
    cin >> num1 >> operation >> num2;
    system("cls");

    switch (operation)
    {
    case '+':
        cout << num1 << " " << operation << " " << num2 << " = " << num1 + num2 << endl;
        break;
    case '-':
        cout << num1 << " " << operation << " " << num2 << " = " << num1 - num2 << endl;
        break;
    case '*':
        cout << num1 << " " << operation << " " << num2 << " = " << num1 * num2 << endl;
        break;
    case '/':
        cout << num1 << " " << operation << " " << num2 << " = " << num1 / num2 << endl;
        break;
    case '%':
        //  cout << num1 << " " << operation << " " << num2  << " = " << num1 % num2 << endl; //дава грешка: float не може да се дели с %

        // bool isNum1Int = (int)num1 == num1; //не разбирам защо така разписано дава грешка
        // bool isNum2Int = (int)num2 == num2;
        bool isNum1Int, isNum2Int;
        isNum1Int = (int)num1 == num1;
        isNum2Int = (int)num2 == num2;

        if (isNum1Int && isNum2Int)
        {
            cout << num1 << " " << operation << " " << num2 << " = " << (int)num1 % (int)num2 << endl;
        }
        else
        {
            cout << "Not valid" << endl;
        }
        break;
    default: // дава грешка, когато се директно се инциализират bool променливите:  bool validNum1 = (int)num1 == num1; bool validNum2 = (int)num2 == num2;
        cout << "Invalid input" << endl;
        break;
    }

    return 0;
}