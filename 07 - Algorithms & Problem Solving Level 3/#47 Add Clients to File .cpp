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


stClient ReadNewClient()
{
	stClient Client;

	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);

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
	SstClientRecord += to_string(Client.AccountBalance);

	return SstClientRecord;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;

		MyFile.close();
	}

}

void AddNewClient()
{
	stClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClintFileName, ConvertRecordToLine(Client));
}

void AddClints()
{
	char AddMore = 'Y';

	do
	{
		system("cls");
		cout << "Adding New Client:\n\n";

		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients? (Y/N)";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');

}

int main()
{
	AddClints();

	return 0;
}