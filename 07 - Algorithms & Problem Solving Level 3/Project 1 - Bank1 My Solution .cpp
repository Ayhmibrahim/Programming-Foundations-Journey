#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>


using namespace std;
const string ClintFileName = "Clint.txt";

void ShowMainMenue();

int ChoiceOptions()
{
	short Choice = 0;

	ShowMainMenue();
	do
	{
	
		cout << "Choose what do you want to do? [1 to 6]? ";
		cin >> Choice;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter a valid one:" << endl;
			cin >> Choice;
		}

	} while (Choice < 1 || Choice > 6);

	return Choice;
}

enum enMainMenueOptions {
	Show = 1, AddNew = 2, Delete = 3,
	Updata = 4, Finde = 5, Exit = 6
};

struct stClients
{
	string AccountNumber;
	string PinCode;
	string ClientName;
	string Phone;
	double Balance = 0;
	bool MarkForDelete = false;
};

stClients ReadNewClient()
{
	stClients Client;

	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);

	cout << "Enter Pin Code? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.ClientName);

	cout << "Enter Pin Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter Pin Balance? ";
	cin >> Client.Balance;

	return Client;
}

stClients ChangeClientRecord(string AccountNumber)
{
	stClients Client;

	Client.AccountNumber = AccountNumber;

	cout << "Enter Pin Code? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.ClientName);

	cout << "Enter Pin Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter Pin Balance? ";
	cin >> Client.Balance;

	return Client;
}

vector <string> SplitString(string S1, string Delim = "#//#")
{
	vector <string> vString;

	short pos = 0;
	string sWord;

	while ((pos =S1.find(Delim)) != std::string::npos)
	{
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

string ConvertRecordToLine(stClients Client, string Seperator ="#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AccountNumber+Seperator;
	stClientRecord += Client.PinCode+Seperator;
	stClientRecord += Client.ClientName+Seperator;
	stClientRecord += Client.Phone+Seperator;
	stClientRecord += to_string(Client.Balance);

	return stClientRecord;
}

stClients ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
	stClients Client;
	vector <string> vClientData;
	vClientData = SplitString(Line, Seperator);


	if (vClientData.size() < 5)
		return Client; 

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.ClientName = vClientData[2];
	Client.Phone = vClientData[3];
	Client.Balance = stod(vClientData[4]);

	return Client;

}

vector <stClients> LoadClientsDataFromLine(string FileName)
{
	vector <stClients> vClients;

	fstream MyFile;
	
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open())
	{
		string Line;
		stClients Clinet;
		while (getline(MyFile, Line))
		{
			Clinet = ConvertLinetoRecord(Line);
			vClients.push_back(Clinet);
		}

		MyFile.close();
	}
	return vClients;
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";
	cout << "\nAccount Number? ";
	cin >> AccountNumber;
	return AccountNumber;
}

vector <stClients> SaveCleintsDataToFile(string FileName, vector <stClients> vClient)
{
	fstream MyFile;
	string DataLine;

	MyFile.open(FileName, ios::out);
	if (MyFile.is_open())
	{
		for (stClients C : vClient)
		{
			if (C.MarkForDelete == false)
			{
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}

	return vClient;
}

void PrintClientCard(stClients& Client)
{
	cout << "\nThe following are the client delails:\n";
	cout << "-----------------------------------\n";

	cout << left;
	cout << setw(20) << "Account Number:" << Client.AccountNumber << endl;
	cout << setw(20) << "Pin Code:" << Client.PinCode << endl;
	cout << setw(20) << "Name:" << Client.ClientName << endl;
	cout << setw(20) << "Phone:" << Client.Phone << endl;
	cout << setw(20) << "Account Balance:" << Client.Balance << endl;


	cout << "\n-----------------------------------\n";
}

void PrintClientRecord(const stClients& Clinet)
{
	cout << "| " << setw(15) << left << Clinet.AccountNumber;
	cout << "| " << setw(10) << left << Clinet.PinCode;
	cout << "| " << setw(35) << left << Clinet.ClientName;
	cout << "| " << setw(12) << left << Clinet.Phone;
	cout << "| " << setw(12) << left << Clinet.Balance;
}

bool MarkDeleteClientByAccountNumber(string AccountNumber, vector <stClients>& vClient)
{
	for (stClients& C : vClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}

	return false;
}

bool FindClientByAccountNumber(string AccountNumber , stClients& Client)
{
	vector <stClients> vClient = LoadClientsDataFromLine(ClintFileName);

	for (stClients& C : vClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<stClients>& vClients)
{
	stClients Client;
	char Answer ='y';

	if (FindClientByAccountNumber(AccountNumber,Client))
	{
		cout << "\n";
		
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;
		if (toupper(Answer)=='Y')
		{
			MarkDeleteClientByAccountNumber(AccountNumber,vClients);

			SaveCleintsDataToFile(ClintFileName, vClients);

			vClients = LoadClientsDataFromLine(ClintFileName);

			cout << "\nClient Delete Successfully.";

			return true;
		}
		else
		{
			cout << "\nDeleted cancelled.\n\n";
			return false;
		}
	}

	cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!";
	return false;
}

bool UpdataClientByAccountNumber(string AccountNumber ,vector<stClients>& vClients)
{
	stClients Client;
	char Answer = 'y';

	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want Updata this client? y/n ? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			
			for (stClients& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}

			SaveCleintsDataToFile(ClintFileName, vClients);
			cout << "\n\nClient Updated  Successfully.";

			return true;
		}
		else
		{
			cout << "\nUpdate cancelled.\n\n";
			return false;
		}
	}
	cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!\n\n";
	return false;
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
	stClients Client;
	string AccountNumber = ReadClientAccountNumber();

	while (FindClientByAccountNumber(AccountNumber, Client))
	{
		cout << "Client already exists, Enter another Account Number: ";
		cin >> AccountNumber;
	}
		
	Client = ReadNewClient();

	Client.AccountNumber = AccountNumber;

	AddDataLineToFile(ClintFileName, ConvertRecordToLine(Client));
}

void DeleteClient()
{
	vector <stClients> vClients = LoadClientsDataFromLine(ClintFileName);
	string AccountNumber = ReadClientAccountNumber();

	DeleteClientByAccountNumber(AccountNumber, vClients);
}

void UpdataClient()
{
	vector <stClients> vClients = LoadClientsDataFromLine(ClintFileName);
	string AccountNumber = ReadClientAccountNumber();

	UpdataClientByAccountNumber(AccountNumber, vClients);
}

void FindClient()
{
	vector <stClients> vClients = LoadClientsDataFromLine(ClintFileName);
	string AccountNumber = ReadClientAccountNumber();

	stClients Client;

	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!\n\n";
	}
}

void PrintAllClientsData(vector <stClients>& vClients)
{
	cout << "\n\t\tClient List (" << vClients.size() << ") Client(s).";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << setw(15) << left << "Account Number";
	cout << "| " << setw(10) << left << "Pin Code";
	cout << "| " << setw(35) << left << "Client Name";
	cout << "| " << setw(12) << left << "Phone";
	cout << "| " << setw(12) << left << "Balance";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	for (stClients &Client : vClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

void AddNewClientsScreen()
{
	cout << "---------------------------------\n";
	cout << "       Add New Clients Screen\n";
	cout << "_________________________________\n";
	cout << "Adding New Client: \n\n";

	char AddMore = 'Y';

	do
	{
		AddNewClient();

		cout << "\n Client Added Successfully, do you want to add more clients? Y/N ?";
		cin >> AddMore;
		
	} while (toupper(AddMore) == 'Y');
}

void DeleteClientsScreen()
{
	cout << "-----------------------------------\n";
	cout << "       Delete Clients Screen\n";
	cout << "-----------------------------------\n";

		DeleteClient();	
}

void UpdataClientsScreen()
{
	cout << "-----------------------------------\n";
	cout << "       Updata Clients Screen\n";
	cout << "-----------------------------------\n";

	UpdataClient();

}

void FindClientsScreen()
{
	cout << "-----------------------------------\n";
	cout << "       Find Clients Screen\n";
	cout << "-----------------------------------\n";

	FindClient();
}

void ShowEndScreen()
{
	cout << "-----------------------------------\n";
	cout << "       Program Ends :-)\n";
	cout << "-----------------------------------\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	system("pause");
}

void GoBackToMainMenue()
{
	cout << "\nPress Enter to go back to Main Menu...";
	system("pause");
}

void Options(int Choice)
{
	vector <stClients> vClients = LoadClientsDataFromLine(ClintFileName);
	enMainMenueOptions ChoiceOption = (enMainMenueOptions)Choice;


	switch (ChoiceOption)
	{
	case enMainMenueOptions::Show:

		system("cls");
		PrintAllClientsData(vClients);
		GoBackToMainMenue();
		break;
	
	case enMainMenueOptions::AddNew:
		system("cls");
		AddNewClientsScreen();
		GoBackToMainMenue();
		break;


	case enMainMenueOptions::Delete:
		system("cls");
		DeleteClientsScreen();
		GoBackToMainMenue();
		break;

	case enMainMenueOptions::Updata:
		system("cls");
		UpdataClientsScreen();
		GoBackToMainMenue();
		break;

	case enMainMenueOptions::Finde :
		system("cls");
		FindClientsScreen();
		GoBackToMainMenue();
		break;

	case enMainMenueOptions::Exit:
		system("cls");
		ShowEndScreen();
		break;
	};
}

void StartBank()
{
	Options(ChoiceOptions());
}

int main()
{
	StartBank();
	return 0;
}
	
void ShowMainMenue()
{
	system("cls");
	cout << "============================================\n";
	cout << "\t\tMain Menue Screen\n";
	cout << "============================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Updata Client Info.\n";
	cout << "\t[5] Finde Client.\n";
	cout << "\t[6] Exit.\n";
	cout << "============================================\n";

}
