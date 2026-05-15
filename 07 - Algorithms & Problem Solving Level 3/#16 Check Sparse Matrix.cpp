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
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

short CountNumberInMatrix(int Matrix1[3][3], int NumberFinde, short Rows, short Cols)
{
	int Counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == NumberFinde)
			{
				Counter++;
			};

		}
	}
	return Counter;
}


bool IsSparseMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int MatrixSize = Rows* Cols;


	return (CountNumberInMatrix(Matrix1, 0, 3, 3) >= (MatrixSize / 2));
}




int main()
{

	int Matrix1[3][3] = {	{1,2,3},{4,5,6},{7,8,9} };
	//int Matrix1[3][3] = { {9,0,0},{0,9,0},{0,0,9} };
	int ScalarNumber;
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsSparseMatrix(Matrix1, 3, 3))
	{
		cout << "\nYes: It is Sparse\n";
	}
	else
	{
		cout << "\n No: It's NOT Sparse\n";

	}
		


	system("pause>0");

}