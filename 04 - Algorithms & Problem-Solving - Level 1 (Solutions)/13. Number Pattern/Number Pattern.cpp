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

void PrintNumberPattern(int Number)
{
    cout << endl;
    for (int i = 1; i <= Number; i++)
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
    PrintNumberPattern(ReadPositiveNumber("Please enter a Positive Number?"));

    return 0;
}