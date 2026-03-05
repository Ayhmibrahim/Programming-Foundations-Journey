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

int CountDigitFrequency(short DigitToCheck, int Number)
{
    int Remainder = 0, FreqCount = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;

        if (DigitToCheck == Remainder)
        {
            FreqCount++;
        }
    } 
    return FreqCount;  
}

void PrintAllDigitFrequencey(int Number)
{
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        short DigitFrequency = CountDigitFrequency(i, Number);

        if (DigitFrequency > 0)
        {
            cout << "Digit " << i << " Frequencey is " << DigitFrequency << " Time.\n";
        }
    }
}

int main()
{
    int Number = ReadPositiveNumber("Please enter The Main Number?");

    PrintAllDigitFrequencey(Number);
}