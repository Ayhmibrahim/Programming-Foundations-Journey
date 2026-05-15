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

int main()
{


	int arr[3][3];
	FillMatrixWithOrderedNumbers(arr, 3, 3);
	cout << "\nThe Folowing is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	system("pause>0");
}