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
	std::cout << "\nEnter the Number to count in Matrix ";
	std::cin >> Number;  // Read the number from the user.
	return Number;  // Return the entered number.
}

int CountNumberInMatrix(int Matrix1[3][3],int NumberFinde, short Rows, short Cols)
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




int main()
{

	//int Matrix1[3][3] = {	{1,2,3},{4,5,6},{7,8,9} };
	int Matrix1[3][3] = { {9,0,0},{0,9,0},{0,0,9} };
	int ScalarNumber;
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	int NumberFinde = ReadNumber();

	cout << "Number " << NumberFinde << " count in matrix? " <<

	CountNumberInMatrix(Matrix1, NumberFinde, 3, 3) << endl;
	

	system("pause>0");

}