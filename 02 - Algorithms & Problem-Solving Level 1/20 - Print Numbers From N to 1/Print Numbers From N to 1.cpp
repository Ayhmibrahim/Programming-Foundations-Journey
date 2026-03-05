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

void PrintRangeFormNto1_UsingWhile(int N)
{
    int Counter = ++N;

    cout << "Range printed using While Statement:\n";

    while (Counter > 1)
    {
        Counter--;
        cout << Counter << endl;
    }
}

void PrintRangeFormNto1_UsingDoWhile(int N)
{
    int Counter = ++N;

    cout << "Range printed using Do..While Statement:" << endl;

    do
    {
        Counter--;
        cout << Counter << endl;
        
    } while (Counter > 1);
}

void PrintRangeFormNto1_UsingFor(int N)
{

    cout << "Range printed using for Statement:" << endl;

    for (int Counter = N; Counter >= 1; Counter--)
    {
        cout << Counter << endl;
    }    
}


int main()
{
    int N = ReadNumber();

    PrintRangeFormNto1_UsingWhile(N);
    PrintRangeFormNto1_UsingDoWhile(N);
    PrintRangeFormNto1_UsingFor(N);

    return 0;
}