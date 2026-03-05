#include <iostream>
using namespace std;

struct stInfo
{
    string FirstName;
    string LastName;
};

stInfo ReadInfo()
{
    stInfo Info;

    cout << "Please Enter FirstName?\n";
    cin >> Info.FirstName;

    cout << "PLease Enter LastName?\n";
    cin >> Info.LastName;

    return Info;
}

string GetFullName(stInfo Info)
{
    string FullName;
    FullName = Info.FirstName + " " + Info.LastName;

    return FullName;
}

void PrintFullName(string FullName)
{
    cout << "\n Your Full Name is: " << FullName << endl;
}


int main()
{
    PrintFullName(GetFullName(ReadInfo()));

    return 0;
}