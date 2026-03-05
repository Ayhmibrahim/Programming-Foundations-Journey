#include <iostream>
#include <cmath>
#include <string>

 using namespace std;

int ReadNumber()
{
    int N;

    cout << "Please enter a number?\n";
    cin >> N;

    return N;
}

void PrintRangeForm1toN_UsingWhile(int N)
{
    int Counter = 0;

    cout << "Range printed using While Statement:\n";

    while (Counter < N)
    {
        Counter++;
        cout << Counter << endl;
    }
}

void PrintRangeForm1toN_UsingDoWhile(int N)
{
    int Counter = 0;

    cout << "Range printed using Do..While Statement" << endl;

    do
    {
        Counter++;
        cout << Counter << endl;

    } while (Counter < N);
}

void PrintRangeForm1toN_UsingFor(int N)
{

    cout << "Range printed using for Statement" << endl;

    for (int Counter = 1; Counter <= N; Counter++)
    {
        cout << Counter << endl;
    }    
}


int main()
{
    int N = ReadNumber();

    PrintRangeForm1toN_UsingWhile(N);
    PrintRangeForm1toN_UsingDoWhile(N);
    PrintRangeForm1toN_UsingFor(N);

    return 0;
}