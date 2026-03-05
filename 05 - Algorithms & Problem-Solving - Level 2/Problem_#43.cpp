#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{

	int randNum = rand() % (To - From + 1) - From;
	return randNum;
}
void FillArray(int arr[100], int& arrLength)
{

	cout << "\nEnter number of elements:\n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
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



int EvenCount(int arrSource[100], int arrLength)
{

	short Counter = 0;

	for (int i = 0; i < arrLength; i++)
	{
		if (arrSource[i] % 2 == 0)
		{
			Counter++;

		}
	}

	return Counter;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength;

	FillArray(arr, arrLength);

	cout << "\nArray Elements: ";
	PrintArray(arr, arrLength);

	cout << "\Even Numbers count is: ";
	cout << EvenCount(arr, arrLength) << endl;

	return 0;
}