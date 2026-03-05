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

void Swap(int &A, int &B)
{
    int Temp;
    
    Temp = A;
    A = B;
    B = Temp;
} 

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillArrayWith1ToN(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
        arr[i] = i + 1;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void ShuffleArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength = ReadPositiveNumber("Enter Number of elements");

    FillArrayWith1ToN(arr, arrLength);

    cout << "\nArray elements before shuffle:\n";
    PrintArray(arr, arrLength);

    ShuffleArray(arr, arrLength);

    cout << "\nArray elements after shuffle:\n";
    PrintArray(arr, arrLength);

    return 0;
}