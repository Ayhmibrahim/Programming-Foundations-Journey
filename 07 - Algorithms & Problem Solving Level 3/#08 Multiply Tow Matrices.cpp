#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void FillMatrixWithRandomNumbers(int Matrix1[3][3], short Rows, short Colum)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Colum; j++)
		{
			Matrix1[i][j] = RandomNumber(0, 10);
		}
	}

}

void PrintMatrix(int Matrix1[3][3], short Rows, short Colum)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Colum; j++)
		{
			printf("%0*d   ", 2, Matrix1[i][j]);
		}

		cout << endl;

	}
}

void MatrixMultiplyNumbers(int Matrix1[3][3],int Matrix2[3][3], 
	int MatrixResults[3][3], short Rows, short Colum)
{
	
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Colum; j++)
		{
			MatrixResults[i][j] = Matrix1[i][j] * Matrix2[i][j];
		}
	}
}


void PrintResults(int MatrixResults[3][3], short Rows, short Colum)
{
	
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Colum; j++)
		{
			printf("%0*d   ", 2, MatrixResults[i][j]);
		}

		cout << endl;
	}
}


int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3], MatrixResults[3][3];
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	MatrixMultiplyNumbers(Matrix1, Matrix2, MatrixResults, 3, 3);
	cout << "\nResult:\n";
	PrintResults(MatrixResults, 3, 3);

	system("pause>0");
}