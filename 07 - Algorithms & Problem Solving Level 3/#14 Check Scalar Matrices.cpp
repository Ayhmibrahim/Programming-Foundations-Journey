#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf(" %0*d ", 2, arr[i][j]);
			//cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

bool IsScalarMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int FirstDiagElemement = Matrix1[0][0];
	
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{	//check for diagonals element
			if (i == j && Matrix1[i][j] != FirstDiagElemement)
			{
				return false;
			}
			else if (i != j && Matrix1[i][j] != 0)
			{
				return false;

			}
		}
	}

	return true;
}

int main()
{

	//int Matrix1[3][3] = {	{1,2,3},{4,5,6},{7,8,9} };
	int Matrix1[3][3] = { {9,0,0},{0,9,0},{0,0,9} };
	int ScalarNumber;
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsScalarMatrix(Matrix1,3, 3))
		cout << "\nYES: both martices are Scalar.";
	else
		cout << "\nNo: martices are NOT Scalar.";

	system("pause>0");

}