#include <iostream>
#include <string>

 using namespace std;

int ReadNumber()
{
    int Number;
    cout << "Please Enter a Number?\n";
    cin >> Number;

    return Number;
}

int ReadPower()
{
    int Number;
    cout << "Please Enter The Power?\n";
    cin >> Number;

    return Number;
}

int PowerNumberOfM(int M, int Number)
{
    if (M == 0)
    {
        return 1;
    }

    int P = 1;

    for (int i = 1; i <= M; i++)
    {
        P *= Number;    
    }

    return P;
}

int main()
{
    cout << endl << PowerNumberOfM(ReadPower(), ReadNumber()) << endl;

    return 0;
}