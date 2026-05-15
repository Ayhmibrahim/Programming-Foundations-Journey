#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<int> vNumber;

   

    vNumber.push_back(10);
    vNumber.push_back(20);
    vNumber.push_back(30);
    vNumber.push_back(40);
    vNumber.push_back(50);
    vNumber.push_back(60);

    cout << "Stack Size = " << vNumber.size() << endl;

    vNumber.pop_back();
    vNumber.pop_back();
    vNumber.pop_back();
    vNumber.pop_back();
 

    cout << "Stack Size = " << vNumber.size() << endl;


    if (vNumber.size() == 2)
        vNumber.clear();

    cout << "Numbers Vector: \n\n";

    
    

    // ranged loop
    for (int& Number : vNumber)
    {
        cout << Number << endl;
    }
    cout << endl;
    return 0;
}