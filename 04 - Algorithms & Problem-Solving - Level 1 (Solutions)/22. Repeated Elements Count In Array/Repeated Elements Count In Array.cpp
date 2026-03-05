#include <iostream>


 using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

void ReadArray(int arr[100], int &arrLength)
{
    cout << "Enter Number of elements:\n";
    cin >> arrLength;

    cout << "Enter array elements: \n";
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element [" << i + 1 << "]: ";
        cin >> arr[i]; 
    }
    cout << endl;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int TimesRepeted(int arr[100], int arrLength, int Number)
{
    int Counter = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if (Number == arr[i])
        {
            Counter++;
        }
    }
    return Counter;
}

int main()
{
    int arr[100], arrLength, CheakToNumber;

    ReadArray(arr, arrLength);

    CheakToNumber = ReadPositiveNumber("Enter the number you want to cheak:");

    cout << "\nOriginal array: ";
    PrintArray(arr, arrLength);

    cout << "Number " << CheakToNumber << " is repeated ";
    cout << TimesRepeted(arr, arrLength, CheakToNumber) << " time(s)\n"; 

    return 0;
}