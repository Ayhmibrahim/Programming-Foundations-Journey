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

void PrintPerfectNumber1ToN(int Number)
{
    cout << endl;
    for (int i = 1; i <= Number; i++)
    {
        if (IsPerfectNumber(i))
        {
            cout << i << endl;
        }        
    }
}

int main()
{
    PrintPerfectNumber1ToN(ReadPositiveNumber("Please enter a Positive Number?"));
    return 0;
}