#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{
    int Num;
    cout << "Please enter your Number?\n";
    cin >> Num;

    return Num;
}

float CalculateHalfNumber(int Num)
{
    return (float) Num / 2;
}

void PrintHalfNumber(int Num)
{
    string Result = "Half of " + to_string(Num) + " is " + to_string(CalculateHalfNumber(Num));
    cout << endl << Result << endl;
}

int main()
{
    PrintHalfNumber(ReadNumber());

    return 0;
}        