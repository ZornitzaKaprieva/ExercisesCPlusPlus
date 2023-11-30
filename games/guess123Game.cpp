#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

/*Цел на играта:
Да се направят максимално много съвпадения между случайно генерираните 3 числа (със стойности 1, 2 или 3) и предположенията на играча.
Печалби:
При едно съвпадение: + 25% от заложената сума
При едно съвпадение: + 50% от заложената сума
При едно съвпадение: + 100% от заложената сума
Играта продължава, докато играчът не се откаже и поиска да вземе спечелената до момента сума или
докато не откаже да заложи нова сума, в случай, че предходната заложена сума се изчерпа*/

int main()
{

    bool endOfGame = false;
    while (endOfGame != true) // 1. main while: играта ще прекъсне, когато играчът откаже да продължи със залозите или остане без сума за залагане и откаже добави нова сума
    {

        // 2. Въвеждане на променливи - сумата за залози и сумата за залагане на игра:
        double betAmount;
        cout << "Enter the bet amount in BGN:" << endl;
        cin >> betAmount;
        system("cls");
        cout << "Your amount is BGN " << betAmount << endl;
        double currentBet;
        cout << "Enter the current bet in BGN:" << endl;
        cin >> currentBet;
        system("cls");
        cout << "Your bet is BGN " << currentBet << endl;

        // 3. Чрез while цикъл даваме възможност играта да продължи, докато играчът има налична сума, или докато cashOut != falsе:
        double profit = 0;
        bool isWin = true;
        bool cashOut = false;
        while (betAmount >= currentBet)
        {
            // 3.1.Чрез random int array системата избира случайни числа от 1 до 3
            const unsigned int sizeOfArray = 3;
            int luckyNumbers[sizeOfArray];
            for (int i = 0; i < sizeOfArray; i++)
            {
                luckyNumbers[i] = 1 + rand() % 3;
            }

            cout << "Type in your 3 guesses and press enter between them. Numbers should be between 1 and 3:" << endl;
            int guess[3]; // 3.2. Въвеждане на предположения от потребителя и проверка, дали въведените числа са от 1 до 3.
            cin >> guess[0] >> guess[1] >> guess[2];

            while (!(guess[0] >= 1 && guess[0] <= 3 && guess[1] >= 1 && guess[1] <= 3 && guess[2] >= 1 && guess[2] <= 3)) // Попадаме в този while, докато се въведат валидни предположения
            {
                cout << "Invalid Numbers. Try again!" << endl;
                cout << "Type in your 3 guesses and press enter between them. Numbers should be between 1 and 3:" << endl; // cin >> guesses[0], guesses[1], guesses[2];
                cin >> guess[0];
                cin >> guess[1];
                cin >> guess[2];
            }

            // 3.3 Според броя на познатите числа, се начислява определена печалба:
            int numberOfGuesses = 0;
            if (guess[0] == luckyNumbers[0])
            {
                numberOfGuesses++;
            }

            if (guess[1] == luckyNumbers[1])
            {
                numberOfGuesses++;
            }

            if (guess[2] == luckyNumbers[2])
            {
                numberOfGuesses++;
            }

            double currentProfit = 0;
            switch (numberOfGuesses)
            {
            case 1:
                currentProfit = currentBet * 0.25;
                isWin = true;
                break;
            case 2:
                currentProfit = currentBet * 0.5;
                isWin = true;
                break;
            case 3:
                currentProfit = currentBet;
                isWin = true;
                break;
            default:
                isWin = false;
                break;
            }

            system("cls"); // Изтрива информацията от конзолата, но кодът продължава да се изпълнява успешно
            cout << "Your guesses are: " << guess[0] << " " << guess[1] << " " << guess[2] << endl;
            cout << "Lucky numbers are: " << luckyNumbers[0] << " " << luckyNumbers[1] << " " << luckyNumbers[2] << endl;
            cout << "Number of matches: " << numberOfGuesses << endl;

            if (isWin)
            {
                cout << "You won BGN " << currentProfit << endl;
                profit += currentProfit;
                betAmount += currentProfit;
                cout << "Your amount is currently BGN " << betAmount << endl;
            }
            else
            {
                cout << "You lost BGN " << currentBet << endl;
                profit -= (currentProfit + currentBet);
                betAmount -= (currentProfit + currentBet);
                cout << "Your amount is currently BGN " << betAmount << endl;
            }

            // 3.4 Ако има достатъчно налична сума, играчът може да реши да продължи със залозите или да се откаже
            if (betAmount >= currentBet)
            {
                char newTry;
                cout << "Will you try again? Enter '9' for NO or any number for YES: " << endl;
                cin >> newTry;

                if (newTry == '9')
                {
                    system("cls"); // Изтрива информацията от конзолата, но кодът продължава да се изпълнява успешно
                    profit >= 0 ? cout << "Your profit is BGN  " << profit << endl : cout << "You lost BGN " << abs(profit) << endl;
                    cout << "Your amount is currently BGN " << betAmount << endl;
                    cashOut = true;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        // END WHILE

        // Ако играчът реши да прибере печалбата (cashOut == true), се извежда подходящо съобщение и програмата приключва.
        // в противен случай се извежда съобщение, че наличната сума не е достатъчна, за да се продължат залозите.
        if (cashOut)
        {
            system("cls"); // Изтрива информацията от конзолата, но кодът продължава да се изпълнява успешно
            cout << "See you soon!" << endl;
            endOfGame == true;
            break; // 3.5 програмата приключва, след като играчът реши да спре да играе
        }
        else
        {
            cout << "Not enough cash!" << endl;
        }

        // 1.1. След като сумата за залози е свършила, се дава възможност на играча да откаже да заложи допълнителна сума или да продължи
        char loadAmount;
        cout << "Will you load more amount for bets? Enter '9' for NO or any number for YES: " << endl;
        cin >> loadAmount;

        if (loadAmount == '9')
        {
            system("cls");
            cout << "See you soon!" << endl;
            endOfGame == true;
            break; // BREAK MAIN WHILE
        }
        else
        {
            system("cls");
        }
    }
    // END MAIN WHILE

    return 0;
}