#include <iostream>
#include <string>

 using namespace std;

int ReadPositiveNumber(string Message)
{
    int N;

    do
    {
        cout << Message << endl;
        cin >> N;

    } while (N < 0);

    return N;
}

int SumFactorial_UsingWhile(int N)
{
    int Counter = ++N, Factorial = 1;

    cout << "Sum Factorial Using While Statement:\n";

    while (Counter > 1)
    {
        Counter--;

        Factorial *= Counter;
    }

    return Factorial;
}

int SumFactorial_UsingDoWhile(int N)
{
    int Counter = ++N, Factorial = 1;

    cout << "Sum Factorial Using Do..While Statement:\n";

    do
    {
        Counter--;
        Factorial *= Counter;

    } while (Counter > 1);

    return Factorial;
}

int SumFactorial_UsingFor(int N)
{
    int Factorial = 1;

    cout << "Sum Factorial Using For Statement:\n";

    for (int Counter = N; Counter >= 1; Counter--)
    {
        Factorial *= Counter;
    }

    return Factorial;
}

int main()
{
    int N = ReadPositiveNumber("Please Enter a Positive Number?");

    cout << SumFactorial_UsingWhile(N) << endl;
    cout << SumFactorial_UsingDoWhile(N) << endl;
    cout << SumFactorial_UsingFor(N) << endl;

    return 0;
}