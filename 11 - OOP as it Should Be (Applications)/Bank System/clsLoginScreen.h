#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsDate.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFaild = false;
		short FaildLoginCount = 0;
		string Username, Password;

		do
		{
			if (LoginFaild)
			{
				FaildLoginCount++;
				cout << "\nInvlaid Username/Password!";
				cout << "\nYou have " << (3-FaildLoginCount) << " Trials to Login.\n\n";
			}

			if (FaildLoginCount < 0)
			{
				cout << "Your are Locked after 3 faild trials.\n\n";
				return false;
			}

			cout << "Enter Username? ";
			cin >> Username;
			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;
	}

	void _Log()
	{

	}

public:
	

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t	Login Screen");
		return _Login();


	}

};

