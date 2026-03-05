#include <iostream>
#include <cstdlib>
#include <cmath>

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

void AddAraayElements(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

void InputUserNumberInArray(int arr[100], int& arrLength)
{
    bool AddMore = true;

    do
    {
        AddAraayElements(ReadNumber(), arr, arrLength);

        cout << "\nDo you want to add more number? [0]:No,[1]:yes?";
        cin >> AddMore;

    } while (AddMore);
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

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return FindNumberPositionInArrey(Number, arr, arrLength) != -1;
}

void CobyDistinctNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
        if (!IsNumberInArray(arrSource[i], arrDestination, arrDestinationLength))
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

    int arrSource[100], SourceLength = 0, arrDestination[100], DestinationLength = 0;

    InputUserNumberInArray(arrSource, SourceLength);

    cout << "\nArray 1 elements:\n";
    PrintArray(arrSource, SourceLength);

    CobyDistinctNumbers(arrSource, arrDestination, SourceLength, DestinationLength);

    cout << "\nArray 2 distinct elements:\n";
    PrintArray(arrDestination, DestinationLength);

    return 0;
}