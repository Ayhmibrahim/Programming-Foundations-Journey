#include <iostream>
#include <string>
#include <cmath>

 using namespace std;

enum enOddOrEven { Odd = 1, Even = 2 };

int ReadNumber()
{
    int N;
    cout << "Please Enter a Number?\n";
    cin >> N;

    return N;
}

enOddOrEven CheckOddOrEven(int Number)
{
    if (Number % 2 != 0)
        return enOddOrEven::Odd;
    else
        return enOddOrEven::Even;
}

int SumOddNumbersForm1toN_UsingWhile(int N)
{
    int Counter = 0, Sum = 0;

    cout << "Sum odd numbers using While statement:\n";

    while (Counter < N)
    {
        Counter++;

        if (CheckOddOrEven(Counter) == enOddOrEven::Odd)
        {
            Sum += Counter;
        }        
    }

    return Sum;    
}

int SumOddNumbersForm1toN_UsingDoWhile(int N)
{
    int Counter = 0, Sum = 0;

     cout << "Sum odd numbers using Do..While statement:\n";

    do
    {
        Counter++;

        if (CheckOddOrEven(Counter) == enOddOrEven::Odd)
        {
            Sum += Counter;
        }

    } while (Counter < N);

    return Sum;    
}

int SumOddNumbersForm1toN_UsingFor(int N)
{
    int Sum = 0;

     cout << "Sum odd numbers using For statement:\n";

    for (int Counter = 1; Counter <= N; Counter++)
    {
        if (CheckOddOrEven(Counter) == enOddOrEven::Odd)
        {
            Sum += Counter;
        }
    }

    return Sum;
}

int main()
{
    int N = ReadNumber();

    cout << SumOddNumbersForm1toN_UsingWhile(N) << endl;
    cout << SumOddNumbersForm1toN_UsingDoWhile(N) << endl;
    cout << SumOddNumbersForm1toN_UsingFor(N) << endl;

    return 0;
}