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

int CountDigitFrequency(int Number, short DigitToCheck)
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

int main()
{
    int Number = ReadPositiveNumber("Please enter The Main Number?");
    short DigitToCheck = ReadPositiveNumber("Please enter One Digit to Check?");

    cout << "\nDigit " << DigitToCheck << " Frequency is " << CountDigitFrequency(Number, DigitToCheck) << " Time(s)" << endl;
    return 0;
}