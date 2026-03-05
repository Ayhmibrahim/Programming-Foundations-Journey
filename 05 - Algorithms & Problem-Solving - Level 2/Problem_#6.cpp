#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;

    } while (Number <= 0);


    return Number;
}

int SumOfDigits(int Number)
{
    int Sum = 0;
    int Reminder = 0;      

    while (Number > 0)
    {
        Reminder = Number % 10;
        Number = Number / 10;
        Sum = Sum + Reminder;
    }

    return Sum;
}
int main()
{
    cout << "\nSum Of Digits = "
    << SumOfDigits(ReadPositiveNumber("Please enter a positive Number"))
    << "n";

    return 0;
}