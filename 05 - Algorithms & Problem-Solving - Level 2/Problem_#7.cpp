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

void PrintDigits(int Number)
{
    int Reminder = 0;
    int Number1 = 0;
    while (Number > 0)
    {
        Reminder = Number % 10;
        Number = Number / 10;
        cout << Reminder + Number1;
    }
}
int main()
{
    PrintDigits(ReadPositiveNumber("Please enter a positive Number"));

    return 0;
}