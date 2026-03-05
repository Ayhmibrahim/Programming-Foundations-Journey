#include <iostream>
#include <cstdlib>

 using namespace std; 

int ReadNumber()
{
    int Number;
    cout << "\nPlease enter a Number?";
    cin >> Number;

    return Number;
}

void AddAraayElements(int Number, int arr[100], int &arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

void InputUserNumberInArray(int arr[100], int &arrLength)
{
    bool AddMore = true;

    do
    {
        AddAraayElements(ReadNumber(), arr, arrLength);

        cout << "\nDo you want to add more number? [0]:No,[1]:yes?";
        cin >> AddMore;

    } while (AddMore);
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
    int arr[100], arr[100], arrLength = 0;

    InputUserNumberInArray(arr, arrLength);

    cout << "\nArray Length: " << arrLength << endl;
    cout << "Array elements: ";
    PrintArray(arr, arrLength);

    return 0;
}