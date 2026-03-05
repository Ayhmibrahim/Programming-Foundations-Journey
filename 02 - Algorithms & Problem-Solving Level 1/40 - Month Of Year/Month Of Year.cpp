#include <iostream>
#include <string>

 using namespace std;

enum enMonthOfYear { January = 1, February = 2, March = 3, April = 4, May = 5, June = 6, July = 7, 
                   August = 8, September = 9, October = 10, November = 11, December = 12 };

int ReadNumberInRange(string Message, int From, int To)
{
    int Number;

    do
    {
        cout << Message << endl;
        cin >> Number;

    } while (Number < From || Number > To);

    return Number;
}

enMonthOfYear ReadMonthOfYear()
{
    int Month = ReadNumberInRange("Please enter Number Of Day: (1)January, (2)February, (3)March, (4)April, (5)May, (6)June, (7)July, (8)August, (9)September, (10)October, (11)November, (12)December", 1, 12);

    return (enMonthOfYear) Month;
}

string GetMonthOfYear(enMonthOfYear Month)
{
    switch (Month)
    {
    case enMonthOfYear::January:
        return "Its January";
    case enMonthOfYear::February:
        return "Its February";
    case enMonthOfYear::March:
        return "Its March";
    case enMonthOfYear::April:
        return "Its April";
    case enMonthOfYear::May:
        return "Its May";
    case enMonthOfYear::June:
        return "Its June";
    case enMonthOfYear::July:
        return "Its July";
    case enMonthOfYear::August:
        return "Its August";
    case enMonthOfYear::September:
        return "Its September";
    case enMonthOfYear::October:
        return "Its October";
    case enMonthOfYear::November:
        return "Its November";
    case enMonthOfYear::December:
        return "Its December";
    default:
        return "Not a valid Manth";
    }
}

int main()
{
    string MonthOfYear = GetMonthOfYear(ReadMonthOfYear());

    cout << endl;
    cout << MonthOfYear << endl;

    return 0;
}