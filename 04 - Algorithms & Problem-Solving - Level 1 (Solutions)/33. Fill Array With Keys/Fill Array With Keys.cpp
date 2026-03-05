#include <iostream>
#include <cstdlib>

 using namespace std; 

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

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

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

char GetRandomCharacter(enCharType CharType)
{
    switch(CharType)
    {
    case enCharType::SmallLetter:
    {
        return char(RandomNumber(97, 122));
    }    
    case enCharType::CapitalLetter:
    {
        return char(RandomNumber(65, 90));
    }   
    case enCharType::SpecialCharacter:
    {
        return char(RandomNumber(33, 47));
    }
    case enCharType::Digit:
    {
        return char(RandomNumber(48, 57));
    }
    default:
        return ' ';
    }
}

string GenerateWord(enCharType CharType, int Length)
{
    string Word = "";

    for (int i = 1; i <= Length; i++)
    {
        Word = Word + GetRandomCharacter(CharType);
    }
    return Word;
}

string GenerateKey()
{
    string Key = "";

    Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + '-';
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

    return Key;
    
}

void FillArrayWithKeys(string arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
        arr[i] = GenerateKey();
}

void PrintStringArray(string arr[100], int arrLength)
{
    cout << "\nArray elements:\n\n";
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Array [" << i + 1 << "] : " << arr[i] << endl;
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    string arr[100];
    int arrLength = ReadPositiveNumber("Enter Number of elements");

    FillArrayWithKeys(arr, arrLength);

    PrintStringArray(arr, arrLength);

    return 0;
}