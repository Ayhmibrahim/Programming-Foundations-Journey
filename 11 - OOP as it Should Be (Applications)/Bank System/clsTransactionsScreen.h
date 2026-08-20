#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTransferScreen.h"
#include "clsTransfersLogScreen.h"
#include "clsTotalBalancesScreen.h"



class clsTransactionsScreen : protected clsScreen
{
private:

	enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eShowTransfer = 3, eShowTransfersLog = 4 ,
		eShowTotalBalance = 5 ,eShowMainMenue = 6 };

	static short ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static  void _GoBackToTransactionsMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";

		system("pause>0");
		ShowTransactionsMenue();
	}

	static void _ShowDepositScreen()
	{
		//cout << "\nDeposit Screen Will be here...\n";
		clsDepositScreen::DepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "\nWithdraw Screen Will be here...\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTransferScreen()
	{
		//cout << "\nTransfer Screen Will be here...\n";
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		//cout << "\nTransfer Log Screen Will be here...\n";
		clsTransfersLogScreen::ShowTransferLogScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		//cout << "\nTotal Balances Screen Will be here...\n";
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
	{
		switch (TransactionMenueOption)
		{
		case enTransactionsMenueOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}


		case enTransactionsMenueOptions::eShowTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMenueOptions::eShowTransfersLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMenueOptions::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		}


		case enTransactionsMenueOptions::eShowMainMenue:
		{
			//do nothing here the main screen will handle it :-) ;
		}
		}

	}

public:

	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}

		system("cls");

		_DrawScreenHeader("\t  Transactions Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tTransactions Menue Screen\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Transfer.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[5] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerfromTranactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
	} 
		
};  

