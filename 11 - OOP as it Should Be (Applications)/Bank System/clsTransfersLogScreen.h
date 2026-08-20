#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"


class clsTransfersLogScreen : protected clsScreen
{
private:

    static void PrintTransfersRegisterRecordLine(clsBankClient::stTransfersLog TransfersLogRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(25) << left << TransfersLogRegisterRecord.DateTime;
        cout << "| " << setw(10) << left << TransfersLogRegisterRecord.AccountNumber1;
        cout << "| " << setw(10) << left << TransfersLogRegisterRecord.AccountNumber2;
        cout << "| " << setw(10) << left << TransfersLogRegisterRecord.Amount;
        cout << "| " << setw(10) << left << TransfersLogRegisterRecord.AccountBalance1;
        cout << "| " << setw(10) << left << TransfersLogRegisterRecord.AccountBalance2;
        cout << "| " << setw(10) << left << TransfersLogRegisterRecord.UserName;

    }

public:

    static void ShowTransferLogScreen()
    {
        vector <clsBankClient::stTransfersLog> vTransfersRegisterRecord = clsBankClient::GetTransfersRegisterList();

        string Title = "\t  Transfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransfersRegisterRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "s.Acct";
        cout << "| " << left << setw(10) << "d.Acct";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s.Balacne";
        cout << "| " << left << setw(10) << "d.Balacne";
        cout << "| " << left << setw(10) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransfersRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Log Available In the System!";
        else

            for (clsBankClient::stTransfersLog Record : vTransfersRegisterRecord)
            {

                PrintTransfersRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }


};

