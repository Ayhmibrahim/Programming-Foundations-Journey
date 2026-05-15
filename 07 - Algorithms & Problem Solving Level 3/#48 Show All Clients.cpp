
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

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

vector <stClient> LoadCleintsDataFromFile(string FileName )
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

void PrintClientRecord(stClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientsData(vector <stClient> vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";

    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl; 

    for (stClient Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}

int main()
{

    vector <stClient> vClients =
        LoadCleintsDataFromFile(ClintFileName);
   
    PrintAllClientsData(vClients);
  
    return 0;
}