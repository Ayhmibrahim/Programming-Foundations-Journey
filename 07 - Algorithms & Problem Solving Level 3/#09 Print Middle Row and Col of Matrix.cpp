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


void PrintMiddleRowOfMatrix(int Matrix1[3][3], short Rows, short Colum)
{

	short MiddleRow = Rows / 2;
		for (short j = 0; j < Colum; j++)
		{
			printf("%0*d   ", 2, Matrix1[MiddleRow][j]);
		}
		cout << "\n";
}

void PrintMiddleColOfMatrix(int Matrix1[3][3], short Rows, short Colum)
{
	short MiddleCol = Colum / 2;
	for (short i = 0; i < Rows; i++)
	{
		printf("%0*d   ", 2, Matrix1[i][MiddleCol]);
	}

	cout << "\n";
}



int main()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int Matrix1[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMiddle Row of Matrix1 is:\n";
	PrintMiddleRowOfMatrix(Matrix1, 3, 3);

	cout << "\nMiddle Col of Matrix1 is:\n";
	PrintMiddleColOfMatrix(Matrix1, 3, 3);
	system("pause>0");

}