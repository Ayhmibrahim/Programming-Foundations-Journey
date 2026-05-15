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

int ReadNumber()
{
	int Number;  // Variable to store the user's input.
	std::cout << "\nPlease Enter the number to look for in matrix? ";
	std::cin >> Number;  // Read the number from the user.
	return Number;  // Return the entered number.
}

int CountNumberInMatrix(int Matrix1[3][3], int NumberFinde, short Rows, short Cols)
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


bool IsExistsMatrix(int Matrix1[3][3],int Number , short Rows, short Cols)
{
	int Counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number)
			{
				return true;
			};

		}
	}
	return false;
}

int main()
{

	int Matrix1[3][3] = {	{1,2,3},{4,5,6},{7,8,9} };
	//int Matrix1[3][3] = { {9,0,0},{0,9,0},{0,0,9} };
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	int NumberFinde = ReadNumber();

	if (IsExistsMatrix(Matrix1, NumberFinde,3,3))
	{
		cout << "\nYes: It is there\n";
	}
	else
	{
		cout << "\nNo: It's NOT there\n";

	}



	system("pause>0");

}