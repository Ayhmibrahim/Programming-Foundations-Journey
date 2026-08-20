#include <iostream>
#include "clsLoginScreen.h"
int main()
{
	//Ctrl + K + D

	while (true)
	{

		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}

	return 0;
}
