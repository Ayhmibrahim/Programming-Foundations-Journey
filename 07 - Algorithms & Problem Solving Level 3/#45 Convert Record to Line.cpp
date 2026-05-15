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

stClient ReadNewClient()
{
	stClient Client;

	cout << "Enter Account Number? ";
	getline(cin, Client.AccountNumber);

	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter Account Balance? ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(stClient Client, string Seperator =
	"#//#")
{
	string SstClientRecord = "";

	SstClientRecord += Client.AccountNumber + Seperator;
	SstClientRecord += Client.PinCode + Seperator;
	SstClientRecord += Client.Name + Seperator;
	SstClientRecord += Client.Phone + Seperator;
	SstClientRecord += to_string(Client.AccountBalance) + Seperator;

	return SstClientRecord;
}

int main()
{
	
	cout << "\nPlease Enter Client Date: \n\n";
	
	stClient Client;
	Client = ReadNewClient();

	cout << "Client Record for Svaing is:\n"
		<< ConvertRecordToLine(Client);

	system("pause>0");
	return 0;
}


