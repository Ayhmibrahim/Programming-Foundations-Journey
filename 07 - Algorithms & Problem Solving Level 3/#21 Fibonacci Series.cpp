#include <iostream>
using namespace std;

void PrintFibonacciUsingLoop(short Number)
{
	int Num1 = 0 , Num2 = 1, F;
	cout << "1  ";
	for (int i = 2; i < Number; i++)
	{
		F = Num1 + Num2;
		cout << F << "  ";
		Num1 = Num2;
		Num2 = F;
	}
}

int main()
{

	PrintFibonacciUsingLoop(10);

    return 0;
}