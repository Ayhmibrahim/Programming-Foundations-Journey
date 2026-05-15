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

int SumOfMatrix(int arr[3][3], short Row, short Colum)
{
	int Sum = 0;
	for (int i = 0; i < Row; i++)
	{
		for (short j = 0; j < Colum ; j++)
		{
			Sum += arr[i][j];
		}
	}


	return Sum;
}


void PrintSumMatrix(int arr[3][3], short Rows, short Colum)
{
	cout << "\nSum Of Matrix1 is: ";

	cout << SumOfMatrix(arr, Rows, Colum) << endl;
}

int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int Matrix1[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);	

	PrintSumMatrix(Matrix1, 3, 3);
	system("pause>0");

}