#include <iostream>
#include <vector>
using namespace std;


void ReadNumbers(vector <int>& vNumbers)
{
    int Number = 0;
    char AddMore = 'Y';
    do
    {
        cout << "Please enter a Number? \n";
        cin >> Number;

        vNumbers.push_back(Number);

        cout << "Do you want add more Vector Number? Y/N? \n";
        cin >> AddMore;

    } while (AddMore == 'Y' || AddMore == 'y');
}

void PrintVector()
{

    vector <int> vNumber;

    ReadNumbers(vNumber);

    std::cout << "\nNumber Vector = \n\n";


    for (int &Numbers :vNumber)
    {
        cout << Numbers << endl;
    }
    cout << endl;
}

int main()
{

    PrintVector();

    return 0;
}