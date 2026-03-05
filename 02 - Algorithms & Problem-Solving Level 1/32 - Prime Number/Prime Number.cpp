#include <iostream>
#include <string>
#include <cmath>

 using namespace std;

enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

int ReadPositiveNumber(string message)
{
    int Number;
    
    do
    {
        cout << message << endl;    
        cin >> Number;

    } while (Number <= 0);
    
    return Number;
}

enPrimNotPrime CheckPrime(int Number)
{
    int M = round( sqrt(Number)); 

    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime;
    }

    return enPrimNotPrime::Prime;
}

void PrintNumberType(int Number)
{
    switch (CheckPrime(Number))
    {
    case enPrimNotPrime::Prime:
        cout << "\nThe Number is Prime\n";
        break;
    case enPrimNotPrime::NotPrime:
        cout << "\n The Number is Not Prime\n";
        break;    
    }
}

int main()
{
    PrintNumberType(ReadPositiveNumber("Please enter a Positive Number?"));

    return 0;
}