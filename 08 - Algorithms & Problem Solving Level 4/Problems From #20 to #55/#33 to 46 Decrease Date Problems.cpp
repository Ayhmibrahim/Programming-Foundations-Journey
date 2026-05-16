#define _CRT_SECURE_NO_WARNINGS
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

bool IsFirstDayInMonth(stDate Date)
{
	return (Date.Day == 1);
}

bool IsFirstMonthInYear(short Month)
{
	return (Month == 1);
}

stDate DecreaseDateByOneDay(stDate Date)
{
	if (IsFirstDayInMonth(Date))
	{
		if (IsFirstMonthInYear(Date.Month))
		{
			Date.Month = 12;
			Date.Day = 31;
			Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
		}
	}
	else
	{
		Date.Day--;
	}
	return Date;
}

stDate DecreaseDateByXDays(short Days,stDate Date)
{
	for (int i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
	for (int i = 0; i < 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

stDate DecreaseDateByXWeeks(short Weeks,stDate Date)
{
	for (int i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	short NumberOfDayInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);

	if (Date.Day > NumberOfDayInCurrentMonth)
	{
		Date.Day = NumberOfDayInCurrentMonth;
	}
	return Date;

}

stDate DecreaseDateByXMonth(short Months,stDate Date)
{
	for (int i = 1; i <= Months ; i++)
	{
		Date = DecreaseDateByOneMonth(Date);

	}
	return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
	Date.Year--;
	return Date;
}

stDate DecreaseDateByXYears(short Years,stDate Date)
{
	for (int i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

stDate DecreaseDateByXYearsFaster(short Years,stDate Date)
{
	Date.Year -= Years;
	return Date;
}

stDate DecreaseDateByOneDecades(stDate Date)
{
	Date.Year -= 10;
	return Date;
}

stDate DecreaseDateByXDecades(short Decades,stDate Date)
{
	for (int i = 1; i <= Decades; i++)
	{
		Date = DecreaseDateByOneDecades(Date);
	}
	return Date;
}

stDate IncreaseDateByXDecadesFaster(short Decade, stDate Date)
{
	Date.Year -= Decade * 10;
	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
	Date.Year -= 100;
	return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
	Date.Year -= 1000;
	return Date;
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

	printf("\nDate After:\n\n");

	Date = DecreaseDateByOneDay(Date);
	printf("01-Subtracting one day is: %d/%d/%d\n",Date.Day,Date.Month,Date.Year);

	Date = DecreaseDateByXDays(10,Date);
	printf("02-Subtracting 10 days is: %d/%d/%d\n",Date.Day,Date.Month,Date.Year);

	Date = DecreaseDateByOneWeek(Date);
	printf("03-Subtracting one week is: %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

	Date = DecreaseDateByXWeeks(10,Date);
	printf("04-Subtracting 10 Weeks is: %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

	Date = DecreaseDateByOneMonth(Date);
	printf("05-Subtracting one month is: %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

	Date = DecreaseDateByXMonth(5, Date);
	printf("06-Subteracting 10 Months is: %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

	Date = DecreaseDateByOneYear(Date);
	printf("07-Subteracting one year is: %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

	Date = DecreaseDateByXYears(10, Date);
	printf("08-Subteracting 10 years is: %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

	Date = DecreaseDateByXYearsFaster(10, Date);
	printf("09-Subteracting 10 years (faster) is: %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

	Date = DecreaseDateByOneDecades(Date);
	printf("10-Subteracting one decade is: %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

	Date = DecreaseDateByXDecades(10, Date);
	printf("11-Subteracting 10 decades is: %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

	Date = IncreaseDateByXDecadesFaster(10, Date);
	printf("12-Subteracting 10 Decades (faster) is: %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

	Date = IncreaseDateByOneCentury(Date);
	printf("13-Subteracting One Century is: %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

	Date = IncreaseDateByOneMillennium(Date);
	printf("14-Subteracting One Millennium is: %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

	system("pause>0");
	return 0;
}