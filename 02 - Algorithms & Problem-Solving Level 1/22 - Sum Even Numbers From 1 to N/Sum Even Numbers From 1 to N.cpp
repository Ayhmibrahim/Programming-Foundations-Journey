#include <iostream>
#include <string>

 using namespace std;

enum enOddOrEven { Odd = 1, Even = 2 };

int ReadNumber()
{
    int N;
    cout << "Please Emter a Number?\n";
    cin >> N;

    return N;
}

enOddOrEven CheckOddOrEven(int Number)
{
    if (Number % 2 == 0)
        return enOddOrEven::Even;
    else
        return enOddOrEven::Odd;
}

int SumEvenNumbersForm1toN_UsingWhile(int N)
{
    int Counter = 0, Sum = 0;

    cout << "Sum Even numbers using While statement:\n";

    while(Counter < N)
    {
        Counter++;

        if (CheckOddOrEven(Counter) == enOddOrEven::Even)
        {
            Sum += Counter;
        }
    }

    return Sum;
}

int SumEvenNumbersFrom1toN_UsingDoWhile(int N)
{
    int Counter = 0, Sum = 0;

    cout << "Sum Even numbers using Do..While statement:\n";

    do
    {
        Counter++;

        if (CheckOddOrEven(Counter) == enOddOrEven::Even)
        {
            Sum += Counter;
        }

    } while (Counter < N);

    return Sum;
}

int SumEvenNumbersFrom1toN_UsingFor(int N)
{
    int Sum = 0;

    cout << "Sum Even numbers using For statement:\n";

    for (int Counter = 1; Counter <= N; Counter++)
    {
        if (CheckOddOrEven(Counter) == enOddOrEven::Even)
        {
            Sum += Counter;
        }
    }

    return Sum;
}

int main()
{
    int N = ReadNumber();

    cout << SumEvenNumbersForm1toN_UsingWhile(N) << endl;
    cout << SumEvenNumbersFrom1toN_UsingDoWhile(N) << endl;
    cout << SumEvenNumbersFrom1toN_UsingFor(N) << endl;

    return 0;
}