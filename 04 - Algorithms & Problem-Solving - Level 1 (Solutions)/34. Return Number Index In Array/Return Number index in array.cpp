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

short FindNumberPositionInArrey(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (Number == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength = ReadPositiveNumber("Enter Number of elements");

    FillArrayWithRandomNumber(arr, arrLength);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    int Number = ReadPositiveNumber("\nPlease enter a number To search for?");
    cout << "Number you are looking for is: " << Number << endl;

    short NumberPosition = FindNumberPositionInArrey(Number, arr, arrLength);
  
    if (NumberPosition == -1)
        cout << "The number is not found :-(" << endl;
    else
    {
        cout << "The Number found at position: " << NumberPosition << endl;
        cout << "The Number found its order  : " << NumberPosition + 1 << endl;
    }

    return 0;
}