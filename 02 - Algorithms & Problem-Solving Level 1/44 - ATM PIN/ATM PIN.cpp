#include <iostream>
#include <string>

 using namespace std;

string ReadPinCode()
{
    string PinCode;

    cout << "Please enter PIN Code?" << endl;
    cin >> PinCode;

    return PinCode;
}

bool login()
{
    string PinCode; 
    do
    {
        PinCode = ReadPinCode();

        if (PinCode == "1234")
        {
            return 1;

        }
        else
        {
            cout << "\nWrong PIN\n";
            system("Color 4F");
        }

    } while (PinCode != "1234");

    return 0;
}


int main()
{
    if (login())
    {
        system ("color 2F");
        cout << "\nYour account balance is " << 7500 << endl;
    }

    return 0;
}