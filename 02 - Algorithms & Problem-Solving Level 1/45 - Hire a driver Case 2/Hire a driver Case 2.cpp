#include <iostream>
using namespace std;

struct stInfo
{
    int Age;
    bool HasDrivingLicense;
    bool HasRecommendation;
};

stInfo ReadInfo()
{
    stInfo Info;

    cout << "Please Enter Your Age?\n";
    cin >> Info.Age;

    cout << "Do you have driver License?\n";
    cin >> Info.HasDrivingLicense;

    cout << "Do you have Recommendtion?\n";
    cin >> Info.HasRecommendation;

    return Info;
}

bool IsAccepted(stInfo Info)
{
    if (Info.HasRecommendation)
    {
        return true;
    }
    else
    {
    return (Info.Age > 21 && Info.HasDrivingLicense);
    }
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