#include <iostream>
#include <vector>
using namespace std;


int main()
{
    // std::vector<T> vector_name;
    vector <int> vNumbers = { 10,20,30,40,50 };

    cout << "Number Vector = ";

    //Ranged Loop
    for (int &Number : vNumbers)
    {
        cout << Number << " ";
    }

    cout << endl;

    return 0;
}