#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsListUsersScreen.h"
#include "clsAddNewUserSecreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUserScreen : protected clsScreen
{
private:

	enum enManageUserOptions {
		eListUser = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
	};

	static short ReadManageUserMenueOptions()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void _GoBackToManageUserScreen()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Users Menue...\n";

		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _ShowListUserScreen()
	{
		//cout << "List User Screen will be here....\n";
		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "Add New User Screen will be here....\n";
		clsAddNewUserSecreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		//cout << "Delete User Screen will be here....\n";
		clsDeleteUserScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "UpDate User Screen will be here....\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		//cout << "Find User Screen will be here....\n";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerfromManageUserMenueOption(enManageUserOptions ManageUserMenueOption)
	{
		switch (ManageUserMenueOption)
		{
		case enManageUserOptions::eListUser:
		{
			system("cls");
			_ShowListUserScreen();
			_GoBackToManageUserScreen();
			break;
		}
		case enManageUserOptions::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUserScreen();
			break;
		}
		case enManageUserOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUserScreen();
			break;
		}
		case enManageUserOptions::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUserScreen();
			break;
		}

		case enManageUserOptions::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUserScreen();
			break;
		}
		case enManageUserOptions::eMainMenue:
		{

		}

		}
	}
	
public:

	static void ShowManageUsersMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		system("cls");

		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tManage User Menu Screen\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List User.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromManageUserMenueOption((enManageUserOptions)ReadManageUserMenueOptions());
	}


};

