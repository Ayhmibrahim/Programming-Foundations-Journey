#include <iostream>

using namespace std;

short DayOfWeekOrder(short Day,short Month,short Year)
{
	short a, y, m, d;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + 12 * a - 2;
	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	d = (Day + y + (y / 4) + (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string DayShortName(short DayOfWeekOrder)
{
	string days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return days[DayOfWeekOrder];
}

short ReadDay()
{
	short Day = 0;

	cout << "\nPlease enter a Day to check? ";
	cin >> Day;
	return Day;
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
	short Month = ReadMonth();
	short Day = ReadDay();

	cout << "\n\nDate      : " << Day << "/" << Month << "/" << Year << endl;
	cout << "Day Order : " << DayOfWeekOrder(Day, Month, Year) << endl;
	cout << "Day Name  : " << DayShortName(DayOfWeekOrder(Day, Month, Year)) << endl;

	system("pause>0");
	return 0;

}