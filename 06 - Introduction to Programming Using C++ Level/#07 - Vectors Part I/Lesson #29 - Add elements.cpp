#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector <char> vNumbers;

    vNumbers.push_back('A');
    vNumbers.push_back('Y');
    vNumbers.push_back('H');
    vNumbers.push_back('M');
   


    std::cout << "My Name in Vector = \n\n";

    for (char &Number : vNumbers)
    {
        cout << Number;
    }
    cout << endl;
    return 0;
}