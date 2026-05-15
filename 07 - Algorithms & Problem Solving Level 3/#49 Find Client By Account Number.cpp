#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string ClintFileName = "Clint.txt";

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

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;

}

vector <stClient> LoadCleintsDataFromFile(string FileName)
{
    vector <stClient> vClients;

    fstream File;
    File.open(FileName, ios::in);//readMod

    if (File.is_open())
    {
        string Line;
        stClient Client;
        while (getline(File, Line))
        {
            stClient Clint = ConvertLinetoRecord(Line);
            vClients.push_back(Clint);
        }

        File.close();
    }

    return vClients;
}

void PrintClientCard(stClient Client)
{
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

bool FindClientByAccountNumber(string AccountNumber,vector <stClient> vClient,stClient& Client)
{

    for (stClient& C : vClient)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }

    return false;
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}

int main()
{
    stClient Client;
    string AccountNumber = ReadClientAccountNumber();

    if (FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
       cout << "\nClient with Account Number (" << AccountNumber <<
           ") is Not Found!";
    }

     system("pause>0");
}


