#include <iostream>

 using namespace std; 

void FillArray(int arr[100], int& arrLength)
{
    arrLength = 6;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;
}

bool IsArrayPalindrome(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] != arr[arrLength - 1 - i])
            return false;
    }
    return true;
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

    int arr[100], arrLength = 0;

    FillArray(arr, arrLength);

    cout << "\nArray elements:\n";
    PrintArray(arr, arrLength);

    if (IsArrayPalindrome(arr, arrLength))
    {
        cout << "\nyes, array is palindrome\n";
    }
    else
        cout << "\nNo, array is Not Palindrome\n";

    return 0;
}