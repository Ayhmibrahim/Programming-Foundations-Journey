#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

enPrimNotPrime CheckPrime(int Number)
{
	int M = round(Number / 2);

	for (int Counter = 2; Counter < M; Counter++)
	{

		if (Number % Counter == 0)
			return enPrimNotPrime::NotPrime;
	}

	return enPrimNotPrime::Prime;
}

int RandomNumber(int From, int To)
{

	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{

	cout << "\nEnter number of elements:\n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = Number;
}

void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Lenght)
{
	for (int i = 0; i < arrLength; i++)
	{

		if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
		{
			AddArrayElement(arrSource[i], arrDestination, arr2Lenght);
		}

	}
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}

	cout << '\n';
}


int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength;

	FillArrayWithRandomNumbers(arr, arrLength);

	int arr2[100];
	int arr2Lenght = 0;
	CopyPrimeNumbers(arr, arr2, arrLength, arr2Lenght);

	cout << "\nArray 1 elements:\n";
	PrintArray(arr, arrLength);

	cout << "\nArray 2 Prime numbers:\n";
	PrintArray(arr2, arr2Lenght);

	return 0;
}