
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
    bool MarkDelete = false;
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

string ConvertRecordToLine(stClient Client, string Seperator =
    "#//#")
{
    string SstClientRecord = "";

    SstClientRecord += Client.AccountNumber + Seperator;
    SstClientRecord += Client.PinCode + Seperator;
    SstClientRecord += Client.Name + Seperator;
    SstClientRecord += Client.Phone + Seperator;
    SstClientRecord += to_string(Client.AccountBalance);

    return SstClientRecord;
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

bool FindClientByAccountNumber(string AccountNumber, vector <stClient>& vClient,stClient& Client)
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

bool MarkDeleteClientByAccountNumber(string AccountNumber, vector <stClient>& vClient)
{
    for (stClient& C : vClient)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkDelete = true;
            return true;
        }
    }

    return false;
}

vector <stClient> SaveCleintsDataToFile(string FileName, vector <stClient> vClient)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    string DataLine;

    if (MyFile.is_open())
    {
        for (stClient C : vClient)
        {
            if (C.MarkDelete==false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();

    }

    return vClient;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient>& vClients)
{
    stClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);

        cout << "\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y'|| Answer == 'Y')
        {
            MarkDeleteClientByAccountNumber(AccountNumber, vClients);

            SaveCleintsDataToFile(ClintFileName, vClients);

            vClients = LoadCleintsDataFromFile(ClintFileName);

            cout << "\n\nClient Deleted Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!";
            return false;
    }

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
    vector  <stClient> Clients = LoadCleintsDataFromFile(ClintFileName);
    string AccountNumber = ReadClientAccountNumber();

    DeleteClientByAccountNumber(AccountNumber, Clients);

    system("pause>0");
}


