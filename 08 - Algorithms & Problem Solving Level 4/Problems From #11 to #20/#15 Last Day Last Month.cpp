#include <iostream>

using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
		return 0;

	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month)) ? true : false;
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

short ReadDay()
{
	short Day = 0;

	cout << "Please enter a Day? ";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month = 0;

	cout << "Please enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year = 0;
	cout << "Please enter a Year? ";
	cin >> Year;
	cout << endl;
	return Year;
}

stDate ReadFullDate()
{
	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

int main()
{
	stDate Date = ReadFullDate();


	if (IsLastDayInMonth(Date))

		cout << "\nYes, Day is Last Day in Month.";
	else
		cout << "\nNo, Day is Not Last Day in Month.";


	if (IsLastMonthInYear(Date.Month))

		cout << "\nYes, Month is Last Month in Year.";
	else
		cout << "\nNo, Month is Not Last Month in Year.";

	system("pause>0");
	return 0;

}