#include <iostream>
#include <string>

 using namespace std;

int ReadAge()
{
    int Age;

    cout << "Please Enter Your Age?\n";
    cin >> Age;

    return Age;
}

bool ValidateNumberInRange(int Number, int From, int To)
{
    return Number >= From && Number <= To;
}

void PrintResulte(int Age)
{
    if (ValidateNumberInRange(Age, 18, 45))
        cout << Age << " is a valid age \n";
    else
        cout << Age << " is invalid age \n";
}

int main()
{
    PrintResulte(ReadAge());

    return 0;
}