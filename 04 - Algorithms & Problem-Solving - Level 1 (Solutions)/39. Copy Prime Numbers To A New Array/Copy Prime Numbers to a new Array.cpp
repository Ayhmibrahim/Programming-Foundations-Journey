#include <iostream>
#include <cstdlib>
#include <cmath>

 using namespace std; 

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

enPrimeNotPrime PrimeNumber(int Number)
{
    int M = round(sqrt(Number));

    for (int i = 2; i <= M; i++)
    {
        if (Number % i == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
}

int ReadNumber()
{
    int Number;
    cout << "\nEnter Number of elements:\n";
    cin >> Number;

    return Number;
}

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillArrayWithRandomNumbers(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

void AddAraayElements(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

void CobyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
        if (PrimeNumber(arrSource[i]) == enPrimeNotPrime::Prime)
        {
            AddAraayElements(arrSource[i], arrDestination, arrDestinationLength);
        }
    
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arr2[100], arrLength2 = 0;
    int arrLength = ReadNumber();
    
    FillArrayWithRandomNumbers(arr, arrLength);
    CobyPrimeNumbers(arr, arr2, arrLength, arrLength2);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    cout << "\nArray 2 Prime Number:\n";
    PrintArray(arr2, arrLength2);

    return 0;
}