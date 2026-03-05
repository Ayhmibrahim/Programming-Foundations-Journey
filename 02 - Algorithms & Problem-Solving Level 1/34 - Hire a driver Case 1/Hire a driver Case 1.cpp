#include <iostream>
using namespace std;

struct stInfo
{
    int Age;
    bool HasDrivingLicense;

};

stInfo ReadInfo()
{
    stInfo Info;

    cout << "Please Enter Your Age?\n";
    cin >> Info.Age;

    cout << "Do you have driver License?\n";
    cin >> Info.HasDrivingLicense;

    return Info;
}

bool IsAccepted(stInfo Info)
{
    return (Info.Age > 21 && Info.HasDrivingLicense);
}

void PrintResult(stInfo Info)
{
    if (IsAccepted(Info))
    {
        cout << "\n Hired" << endl;
    }
    else
    {
        cout << "\n Rejected" << endl;
    }
}

int main()
{
    PrintResult(ReadInfo());

    return 0;
}