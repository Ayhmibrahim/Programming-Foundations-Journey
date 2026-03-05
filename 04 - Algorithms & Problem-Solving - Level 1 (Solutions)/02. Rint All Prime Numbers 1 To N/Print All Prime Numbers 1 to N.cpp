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

void PrintPrimeNumbersFrom1ToN(int Number)
{
    cout << endl;
    cout << "Prime Numbers from " << 1 << " To " << Number << " are : \n";

    for (int i = 1; i <= Number; i++)
    {
        if (CheckPrime(i) == enPrimNotPrime::Prime)
            cout << i << endl;            
    }
}

int main()
{
    PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Please enter a Positive Number?"));

    return 0;
}