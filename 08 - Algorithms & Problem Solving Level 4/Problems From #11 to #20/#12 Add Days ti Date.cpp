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

short NumberOfDaysFromTheBeginningOfYear(short Day, short Month, short Year)
{
	int TotalDays = 0;

	for (int m = 1; m <= Month - 1; m++)
	{
		TotalDays += NumberOfDaysInAMonth(m, Year);

	}

	TotalDays += Day;

	return TotalDays;
}

struct sDate
{
	short Year;
	short Month;
	short Day;
};

sDate AddDaysToDate(short Days, sDate Date)
{
	int RemainingDays = Days + NumberOfDaysFromTheBeginningOfYear(Date.Day, Date.Month, Date.Year);
	short MonthDays = 0;

	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
		
		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}
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

sDate ReadFullDate()
{
	sDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

short ReadDaysToAdd()
{
	short Days;
	cout << "\nHow many days to add? ";
	cin >> Days;
	return Days;
}

int main()
{
	sDate Date = ReadFullDate();
	short Days = ReadDaysToAdd();

	Date = AddDaysToDate(Days, Date);
	cout << "\nDate after adding [" << Days << "] days is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;

}