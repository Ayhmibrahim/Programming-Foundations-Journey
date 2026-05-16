#include <iostream>

using namespace std;


bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInYear(short Year)
{
	return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInYear(short Year)
{
	return NumberOfDaysInYear(Year) * 24;
}

int NumberOfMinutesInYear(short Year)
{
	return NumberOfHoursInYear(Year) * 60;
}

int NumberOfSecondsInYear(short Year)
{
	return NumberOfMinutesInYear(Year) * 60;
}

short ReadYear()
{
	short Year = 0;
	cout << "Please enter a year to check? ";
	cin >> Year;
	return Year;
}


int main()
{
	short Year = ReadYear();

	cout << "\n\nNumber Of Days	  in Year [" << Year << "] is "
		<< NumberOfDaysInYear(Year) << endl;

	cout << "Number Of Hours   in Year [" << Year << "] is " 
		<< NumberOfHoursInYear(Year) << endl;

	cout << "Number Of Minutes in Year [" << Year << "] is "
		<< NumberOfMinutesInYear(Year) << endl;

	cout << "Number Of Seconds in Year [" << Year << "] is "
		<< NumberOfSecondsInYear(Year) << endl;

	cout << "\n\n";
	system("pause>0");
	return 0;

}