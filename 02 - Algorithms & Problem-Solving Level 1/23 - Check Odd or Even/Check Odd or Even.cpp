#include <iostream>
using namespace std;

enum enNumberType { Odd = 1, even = 2 };

int ReadNumber()
{
    int Number;

    cout << "Please Enter Number?\n";
    cin >> Number;

    return Number;
}

enNumberType CheckNumberType(int Number)
{
    int Result = Number % 2;
    switch (Result)
    {
    case 0:
        return enNumberType::even;

    default:
        return enNumberType::Odd;
    } 
}

void PrintNumberType(enNumberType Number)
{
    switch (Number)
    {
    case enNumberType::even:
        cout << "\n Number is Even \n";
        break;

    default:
        cout << "\n Number is Odd \n";
    }
}

int main()
{
    PrintNumberType(CheckNumberType(ReadNumber()));

    return 0;
}