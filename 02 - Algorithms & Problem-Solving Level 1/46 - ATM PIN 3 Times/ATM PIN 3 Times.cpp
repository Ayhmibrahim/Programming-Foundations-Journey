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
    int Counter = 3; 
    do
    {
        Counter--;
        PinCode = ReadPinCode();

        if (PinCode == "1234")
        {
            return 1;

        }
        else
        {
            system("Color 4F");
            cout << "\nWrong PIN, you have " << Counter << " more tries\n";    
        }

    } while (Counter >= 1 && PinCode != "1234");

    return 0;
}


int main()
{
    if (login())
    {
        system ("color 2F");
        cout << "\nYour account balance is " << 7500 << endl;
    }
    else
    {
        cout << "\n Your card blocked call the bank for help. \n";
    }

    return 0;
}