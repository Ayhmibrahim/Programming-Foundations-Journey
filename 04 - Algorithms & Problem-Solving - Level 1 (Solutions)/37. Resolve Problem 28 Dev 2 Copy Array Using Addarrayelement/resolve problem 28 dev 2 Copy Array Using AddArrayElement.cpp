#include <iostream>
#include <cstdlib>

 using namespace std; 

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

void AddArrayElements(int Number, int arr[100], int &arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

void CopyArrayUsingAddArrayElements(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        AddArrayElements(arrSource[i], arrDestination, arrDestinationLength);
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
    CopyArrayUsingAddArrayElements(arr, arr2, arrLength, arrLength2);

    cout << "\nArray elements: \n";
    PrintArray(arr, arrLength);

    cout << "\nArray 2 elements after Copy: \n";
    PrintArray(arr2, arrLength2);

    return 0;
}