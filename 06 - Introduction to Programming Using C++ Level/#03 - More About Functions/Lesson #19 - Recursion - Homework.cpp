#include <iostream>
using namespace std;

void PrintNumbers(int N, int M)
{
	if (N >= M)
	{
		cout << N << endl;
		PrintNumbers(N - 1 , M);
	}
}
int main()
{
	PrintNumbers(100, 1);

	return 0;
}