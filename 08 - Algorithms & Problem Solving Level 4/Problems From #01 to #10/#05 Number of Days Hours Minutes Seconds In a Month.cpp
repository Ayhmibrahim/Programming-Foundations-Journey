#include <iostream>

using namespace std;


bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
		return 0;

	if (Month == 2)
		return IsLeapYear(Year) ? 29 : 28;
	
	short arr31Days[7] = { 1,3,5,7,8,10,12 };
	
	for (short i = 0; i <= 12; i++)
	{
		if (arr31Days[i - 1] == Month)
			return 31;
	}

	return 30;
}

short NumberOfHoursInMonth(short Year, short Month)
{
	return NumberOfDaysInMonth(Year, Month) * 24;
}

int NumberOfMinutesInMonth(short Year, short Month)
{
	return NumberOfHoursInMonth(Year, Month) * 60;
}

int NumberOfSecondsInMonth(short Year, short Month)
{
	return NumberOfMinutesInMonth(Year, Month) * 60;
}

short ReadYear()
{
	short Year = 0;
	cout << "Please enter a year to check? ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month = 0;

	do
	{
		cout << "\nPlease enter a Month to check? ";
		cin >> Month;

	} while (Month < 1 || Month > 12);

	return Month;
}


int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber Of Days	  in Month [" << Month << "] is "
		<< NumberOfDaysInMonth(Year, Month) << endl;

	cout << "Number Of Hours   in Month [" << Month << "] is "
		<< NumberOfHoursInMonth(Year, Month) << endl;

	cout << "Number Of Minutes in Month [" << Month << "] is "
		<< NumberOfMinutesInMonth(Year, Month) << endl;

	cout << "Number Of Seconds in Month [" << Month << "] is "
		<< NumberOfSecondsInMonth(Year, Month) << endl;

	system("pause>0");
	return 0;

}