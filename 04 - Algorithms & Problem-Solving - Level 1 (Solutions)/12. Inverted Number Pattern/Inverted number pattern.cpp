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
    } while(Number <= 0);

    return Number;
}

void PrintInvertedNumberPattern(int Number)
{
    cout << endl;
    for (int i = Number; i >= 1; i--)
    {
        for (int J = 1; J <= i; J++)
        {
            cout << i;
        }

        cout << endl;
    }
}

int main()
{
    PrintInvertedNumberPattern(ReadPositiveNumber("Please enter a Positive Number?"));

    return 0;
}