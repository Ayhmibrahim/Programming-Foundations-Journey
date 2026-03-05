#include <iostream>
#include <cstdlib>

 using namespace std;

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

void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arrDestination[i] = arrSource[i];
}

int main()
{
    int arr[100], arr2[100], arrLength;

    srand((unsigned)time(NULL));

    FillArrayWithRandomNumbers(arr, arrLength);

    CopyArray(arr, arr2, arrLength);

    cout << "\nArray Elements 1:\n";
    PrintArray(arr, arrLength);

    cout << "\nArray 2 Elements after Copy:\n";
    PrintArray(arr2, arrLength);

    return 0;
}