#include <iostream>

using namespace std;

bool isLeapYear(short Year)
{
	// if year is divisible by 4 AND not divisible by 100
	// OR if year is divisible by 400
	// then it is a leap year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
		/ 12)) % 7;
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
		days[Month - 1];
}

short DaysFromTheBeginningOfYear(short Day, short Month, short Year)
{
	int TotalDays = 0;

	for (int m = 1; m <= Month - 1; m++)
	{
		TotalDays += NumberOfDaysInAMonth(m, Year);

	}

	TotalDays += Day;

	return TotalDays;
}

struct stDate
{
	short Year;
	short Month;
	short Day;
};

stDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{

	stDate Date;
	short RemainingDays = DateOrderInYear;
	short MonthDays = 0;

	Date.Year = Year;
	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}

	return Date;
}

short ReadDay()
{
	short Day = 0;

	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month = 0;

	cout << "\nPlease enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year = 0;
	cout << "\nPlease enter a Year? ";
	cin >> Year;
	return Year;
}


int main()
{
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	short DayOrderInYear = DaysFromTheBeginningOfYear(Day, Month, Year);

	cout << "\nNumber Of Days from the begining of the year is "
		<< DayOrderInYear << "\n\n";


	stDate Date;
	Date = GetDateFromDayOrderInYear(DayOrderInYear, Year);
	cout << "Date for [" << DayOrderInYear << "] is : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;

}