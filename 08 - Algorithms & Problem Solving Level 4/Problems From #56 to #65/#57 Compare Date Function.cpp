#include <iostream>

using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
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

	printf("\nEnter Date1:\n");
	stDate Date1 = ReadFullDate();

	printf("\nEnter Date2:\n");
	stDate Date2 = ReadFullDate();

	printf("\nCompare Result = %d", CompareDate(Date1, Date2));

	system("pause>0");
	return 0;

}