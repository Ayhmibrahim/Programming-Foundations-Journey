
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector <string> SplitString(string S1, string Delim = "#//#")
{
    vector <string> vString;

    short pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != std::string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

stClient ConvertLinetoRecord(string Line, string Seperator =
    "#//#")
{
    stClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator );

     Client.AccountNumber = vClientData[0];
     Client.PinCode = vClientData[1];
     Client.Name = vClientData[2];
     Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;

}

void PrintClientRecord(stClient Client)
{
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

int main()
{
    string stLine = "A200#//#2070#//#Ayhm Ibrahim Mohmmed Almwmri#//#0569112070#//#3000.000000";

    cout << "Line Record is: \n" << stLine;

    cout << "The following is the extracted client record: \n\n";

    stClient Client = ConvertLinetoRecord(stLine);

    PrintClientRecord(Client);

    return 0;
}