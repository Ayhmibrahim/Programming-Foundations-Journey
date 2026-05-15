#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Colum)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Colum; j++)
		{
			arr[i][j] = RandomNumber(0, 100);
		}
	}

}



void PrintMatrix(int arr[3][3], short Rows, short Colum)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Colum; j++)
		{
			cout << setw(3) << arr[i][j] << "   ";


		}

		cout << endl;

	}
}

int RowSum(int arr[3][3], short RowNumber, short Colum)
{
	int Sum = 0;
	for (short j = 0; j <= Colum - 1; j++)
	{
			Sum += arr[RowNumber][j];
	}

	return Sum;
}

void PrintEachRowSum(int arr[3][3], short Rows, short Colum)
{
	cout << "\nThe Folowing are the sum of each row in the matrix:\n";

	for (short i = 0; i < Colum; i++)
	{
		cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i, Colum) << endl;
	}
	
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];
	FillMatrixWithRandomNumbers(arr, 3, 3);
	cout << "\nThe Folowing is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);
	PrintEachRowSum(arr, 3, 3);

	system("pause>0");
}