#include <iostream>
#include "clsDate.h";

using namespace std;



int main()
{
	clsDate Date;
	
	clsDate Date2(24, 11, 2003);

	cout << Date2.CulculateMyAgeInDays(Date) << endl;

	cout << Date2.GetDifferenceInNegativeDays(Date,true) << endl;
	return 0;

}