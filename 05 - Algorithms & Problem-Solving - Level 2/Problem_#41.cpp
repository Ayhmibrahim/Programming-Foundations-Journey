#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;


void FillArray(int arr[100], int& arrLength)
{

	arrLength = 10;
	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 50;
	arr[4] = 50;
	arr[5] = 70;
	arr[6] = 70;
	arr[7] = 70;
	arr[8] = 70;
	arr[9] = 90;
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{

		if (arr[i] == Number)
			return i;
	}

	return -1;
}

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
	return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}

	cout << '\n';
}



bool IsPalindromeArray(int arr[100], int Length)
{

	for (int i = 0; i < Length; i++)
	{
		if (arr[i] != arr[Length-1])
		{
			return false;
		}
	
	}
	return true;
}
int main()
{
	srand((unsigned)time(NULL));

	int arr[100];
	int Length = 0;

	FillArray(arr, Length);

	cout << "\nArray 1 elements:\n";
	PrintArray(arr, Length);


	if (IsPalindromeArray(arr,Length))
		cout << "\nYes array is Palindrome\n";
	else
		cout << "\nNO array is NOT Palindrome\n";

	return 0;
}