#include <iostream>
#include <cstdlib>

 using namespace std;

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

void FillArrayWithRandomNumber(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void ReverseArray(int arr[100], int arr2[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr2[i] = arr[arrLength - 1 - i];
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arr2[100];
    int arrLength = ReadPositiveNumber("Enter Number of elements");

    FillArrayWithRandomNumber(arr, arrLength);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    CopyArrayInReverseOrder(arr, arr2, arrLength);

    cout << "\nArray 2 elements after copying array 1 in reversed order:\n";
    PrintArray(arr2, arrLength);

    return 0;
}