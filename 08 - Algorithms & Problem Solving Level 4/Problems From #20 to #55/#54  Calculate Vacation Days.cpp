#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
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

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}

	}
	else
	{
		Date.Day++;
	}
	return Date;
}

int	GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);

	}

	return IncludeEndDay ? ++Days : Days;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m, d;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + 12 * a - 2;
	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

short DayOfWeekOrder(stDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

short DaysUntilTheEndOfWeek(stDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

short DaysUntilTheEndOfMonth(stDate Date)
{
	stDate EndOfMonthDate;
	EndOfMonthDate.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
	EndOfMonthDate.Month = Date.Month;
	EndOfMonthDate.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfMonthDate, true);
}

short DaysUntilTheEndOfYear(stDate Date)
{
	stDate EndOfYearDate;
	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfYearDate, true);
}

string DayShortName(short DayOfWeekOrder)
{
	string days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return days[DayOfWeekOrder];
}

bool IsItEndOfWeek(stDate  Date)
{
	return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(stDate Date)
{
	//Weekends are Fri and Sat
	short DayIndex = DayOfWeekOrder(Date);
	return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{
	//Weekends are Sun,Mon,Tue,Wed and Thur
/* short DayIndex = DayOfWeekOrder(Date);
return (DayIndex >= 5 && DayIndex <= 4);
*/
//shorter method is to invert the IsWeekEnd: this will save updating code.
	return !IsWeekEnd(Date);
}

short CalculateVacationDays(stDate DateForm, stDate Date2)
{
	short DaysCount = 0;
	while (IsDate1BeforeDate2(DateForm,Date2))
	{
		if (IsBusinessDay(DateForm))
			DaysCount++;

			DateForm = IncreaseDateByOneDay(DateForm);
	}
	return DaysCount;
}

short ReadDay()
{
	short Day = 0;

	cout << "Please enter a Day to check? ";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month = 0;

	do
	{
		cout << "Please enter a Month to check? ";
		cin >> Month;

	} while (Month < 1 || Month > 12);

	return Month;
}

short ReadYear()
{
	short Year = 0;
	cout << "Please enter a year to check? ";
	cin >> Year;
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
	printf("Vacation Starts:\n");
	stDate DateForm = ReadFullDate();

	printf("\nVacation Ends:\n");
	stDate Date2 = ReadFullDate();


	printf("\nVacation From: %s ,%d/%d/%d\n", DayShortName(DayOfWeekOrder(DateForm)).c_str()
		, DateForm.Day, DateForm.Month, DateForm.Year);

	printf("Vacation To: %s ,%d/%d/%d\n\n", DayShortName(DayOfWeekOrder(Date2)).c_str()
		, Date2.Day, Date2.Month, Date2.Year);
	
	printf("Actucal Vacation Days is: %d", CalculateVacationDays(DateForm, Date2));

	system("pause>0");
	return 0;
}