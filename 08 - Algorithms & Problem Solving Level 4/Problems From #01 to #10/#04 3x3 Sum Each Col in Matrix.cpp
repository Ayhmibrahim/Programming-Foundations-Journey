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

int ColSum(int arr[3][3], short Row, short ColumNumber)
{
	int Sum = 0;
	for (short i = 0; i <= Row - 1; i++)
	{
			Sum += arr[i][ColumNumber];
	}
	




	return Sum;
}

void PrintEachColSum(int arr[3][3], short Rows, short Colum)
{
	cout << "\nThe Folowing are the sum of each col in the matrix:\n";

	for (short j = 0; j < Colum; j++)
	{
		cout << " Col " << j + 1 << " Sum = " << ColSum(arr, Colum,j ) << endl;
	}
	
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];
	FillMatrixWithRandomNumbers(arr, 3, 3);
	cout << "\nThe Folowing is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	PrintEachColSum(arr, 3, 3);
	system("pause>0");
}