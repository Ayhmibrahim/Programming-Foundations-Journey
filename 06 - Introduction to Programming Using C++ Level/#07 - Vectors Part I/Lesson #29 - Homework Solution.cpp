#include <iostream>
#include <vector>
using namespace std;


void ReadNumber(vector <int> & vNumber)
{
    short Number;
    char ReadMore = 'Y';

    while (ReadMore == 'Y' || ReadMore == 'y')
    {
        cout << "Please enter a Number? \n";
        cin >> Number;

        vNumber.push_back(Number);

        cout << "\nDo you want to read more number? Y/N? ";
        cin >> ReadMore;
    }
}

void PrintVectorNumbers(vector <int> & vNumber)
{

    cout << "Numbers Vector: \n\n";

    //ranged Loop
    for (int Number : vNumber)
    {
        cout << Number << endl;
    }
    cout << endl;

}

int main()
{
    vector <int> vNumber;

    ReadNumber(vNumber);
    PrintVectorNumbers(vNumber);

    return 0;
}