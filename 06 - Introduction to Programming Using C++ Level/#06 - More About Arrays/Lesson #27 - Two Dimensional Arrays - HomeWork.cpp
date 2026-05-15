#include <iostream>

using namespace std;

int main()
{
	int x[3][3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			x[i][j] = (1 + i)* (1+j);
		}

	}

	for (int i = 0; i < 3; i++)
	{
	
		for (int j = 0; j < 3; j++)
		{
			
			printf("%0*d ", 2, x[i][j]);
		}
		cout << endl;
	}
}