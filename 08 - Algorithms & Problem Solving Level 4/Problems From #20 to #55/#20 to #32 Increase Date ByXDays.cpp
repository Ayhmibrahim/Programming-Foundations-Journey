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

stDate IncreaseDateByXDays(short Days ,stDate Date)
{
	for (int i = 1; i <= Days; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
	for (int i = 0; i < 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

stDate IncreaseDateByXWeeks(short Weeks,stDate Date)
{
	for (int i = 1; i <= Weeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}
	return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;

	}
	else
	{
		Date.Month++;
	}
	//last check day in date should not exceed max days in thecurrent month
	// example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should
	// be 28/2/2022

	short NumberOfDayInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
	if (Date.Day > NumberOfDayInCurrentMonth)
	{
		Date.Day = NumberOfDayInCurrentMonth;
	}

	return Date;
}

stDate IncreaseDateByXMonths(short Months,stDate Date)
{
	for (int i = 1; i <= Months; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}
	return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
	Date.Year++;
	return Date;
}

stDate IncreaseDateByXYears(short Years, stDate Date)
{
	for (int i = 1; i <= Years; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

stDate IncreaseDateByXYearsFaster(short Years, stDate Date)
{
	Date.Year += Years;
	return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
	Date.Year += 10;
	return Date;
}

stDate IncreaseDateByXDecades(short Decade, stDate Date)
{
	for (int i = 1; i <= Decade *10; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

stDate IncreaseDateByXDecadesFaster(short Decade,stDate Date)
{
	Date.Year += Decade * 10;
	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
	//Period of 1000 years
	Date.Year += 100;
	return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
	//Period of 1000 years
	Date.Year += 1000;
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
	stDate Date1 = ReadFullDate();
	

	printf("\nDate After:\n\n");

	Date1 = IncreaseDateByOneDay(Date1);
	printf("01-Adding one day is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByXDays(10,Date1);
	printf("02-Adding 10 days is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByOneWeek(Date1);
	printf("03-Adding one week is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByXWeeks(10,Date1);
	printf("04-Adding 10 weeks is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByOneMonth(Date1);
	printf("05-Adding one month is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByXMonths(5,Date1);
	printf("06-Adding 5 months is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByOneYear(Date1);
	printf("07-Adding one year is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByXYears(10,Date1);
	printf("08-Adding 10 Years is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByXYearsFaster(10,Date1);
	printf("09-Adding 10 Years (faster) is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByOneDecade(Date1);
	printf("10-Adding one Decade is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByXDecades(10,Date1);
	printf("11-Adding 10 Decades is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByXDecadesFaster(10,Date1);
	printf("12-Adding 10 Decades (faster) is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByOneCentury(Date1);
	printf("13-Adding One Century is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByOneMillennium(Date1);
	printf("14-Adding One Millennium is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

	system("pause>0");
	return 0;
}