#include <iostream>
#include <string>

 using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message << endl;
        cin >> Number;

    } while (Number < 0);

    return Number;
}

bool IsPerfectNumber(int Number)
{
    int Sum = 0;
    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
            Sum += i;
    }

    return Number == Sum;   
}

void PrintResults(int Number)
{
    if (IsPerfectNumber(Number))
        cout << Number << " is Perfect Number.\n";
    else
        cout << Number << " is Not Perfect Number.\n";
}

int main()
{
    PrintResults(ReadPositiveNumber("Please enter a Positive Number?"));
    return 0;
}