#include <iostream>
#include <cstdlib>
#include <cmath>

 using namespace std;

enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

enPrimNotPrime CheakPrime(int Number)
{
    int M = round( sqrt(Number));

    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
        {
            return enPrimNotPrime::NotPrime;
        }
    }
    return enPrimNotPrime::Prime;
} 

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter Number of elements:\n";
    cin >> arrLength;

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

void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arrLength2)
{
    int Counter = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if (CheakPrime(arrSource[i]) == enPrimNotPrime::Prime)
        {
            arrDestination[Counter] = arrSource[i];
            Counter++; 
        }
    }
    arrLength2 = Counter;
}

int main()
{
    int arr[100], arrLength;

    srand((unsigned)time(NULL));

    FillArrayWithRandomNumbers(arr, arrLength);

    int arr2[100], arrLength2;
    CopyOnlyPrimeNumbers(arr, arr2, arrLength, arrLength2);

    cout << "\nArray Elements 1:\n";
    PrintArray(arr, arrLength);

    cout << "\nPrime Number In Array2:\n";
    PrintArray(arr2, arrLength2);

    return 0;
}