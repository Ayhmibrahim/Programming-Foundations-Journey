#include <iostream>
#include <cstdlib>
#include <cmath>

 using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

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

void FillArrayWithRandomNumbers(int arr[100], int arrLength)
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


void SumOf2Arrays(int arr[100], int arr2[100], int arrSum[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arrSum[i] = arr[i] + arr2[i];
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arr2[100], arrSum[100];
    int arrLength = ReadPositiveNumber("Enter Number of elements");

    FillArrayWithRandomNumbers(arr, arrLength);
    FillArrayWithRandomNumbers(arr2, arrLength);

    SumOf2Arrays(arr, arr2, arrSum, arrLength);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    cout << "\nArray 2 elements:\n";
    PrintArray(arr2, arrLength);

    cout << "\nSum Of Array 1 and Array 2 elements:\n";
    PrintArray(arrSum, arrLength);

    return 0;
}