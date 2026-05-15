#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Colum)
{
	int Counter = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Colum; j++)
		{
			Counter++;
			arr[i][j] = Counter;
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

void TransposedMatrix(int arr[3][3],int arrTransposed[3][3], short Rows, short Colum)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Colum; j++)
		{
			arrTransposed[i][j] = arr[j][i];
		}
	}
}

int main()
{

	int arr[3][3], arrTransposed[3][3];

	FillMatrixWithOrderedNumbers(arr, 3, 3);
	cout << "\nThe Folowing is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	TransposedMatrix(arr, arrTransposed, 3, 3);
	cout << "\nThe following is the transposed matrix:\n";
	PrintMatrix(arrTransposed, 3, 3);
	system("pause>0");
}