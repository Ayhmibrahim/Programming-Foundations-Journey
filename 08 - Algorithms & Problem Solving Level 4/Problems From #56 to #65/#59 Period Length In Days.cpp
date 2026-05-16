#include <iostream>

using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

struct stPeriod
{
	stDate StartDate;
	stDate EndDate;
};

enum enCompareDates
{
	Before = -1, Equal = 0, After = 1
};

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month ==
		Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false)
		: false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1AfterDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enCompareDates CompareDate(stDate Date1, stDate Date2)
{

	if (IsDate1BeforeDate2(Date1, Date2))
		return enCompareDates::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enCompareDates::Equal;

	return enCompareDates::After;
}

bool IsOverLap(stPeriod Period1, stPeriod Period2)
{
	if (
		CompareDate(Period2.EndDate, Period1.StartDate) == enCompareDates::Before
		||
		CompareDate(Period2.StartDate, Period1.EndDate) == enCompareDates::After

		)
		return false;
	else
		return true;

}



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

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);

	}

	return IncludeEndDay ? ++Days : Days;
}

int PeriodLengthInDays(stPeriod Period1, bool IncludeEndDay = false)
{
	return GetDifferenceInDays(Period1.StartDate, Period1.EndDate, IncludeEndDay);
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

stPeriod ReadPeriod()
{
	stPeriod Period;
	cout << "Enter Start Date:\n\n";
	Period.StartDate = ReadFullDate();
	cout << "\nEnter End Date:\n";
	Period.EndDate = ReadFullDate();
	return Period;
}

int main()
{

	cout << "\nEnter Period 1:\n";
	stPeriod Period1 = ReadPeriod();

	printf("Period Length is: %d\n", PeriodLengthInDays(Period1));
	printf("Period Length (Including End Date) is: %d", PeriodLengthInDays(Period1,true));

	system("pause>0");
	return 0;

}