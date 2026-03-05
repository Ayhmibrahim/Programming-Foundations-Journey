#include <iostream>
#include <string>

 using namespace std;

enum enWeeksDays { Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7};

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

enWeeksDays PrintMinueWeeksDays()
{
    int WeekDay = ReadNumberInRange("Please enter Number Of Day: (1)Sunday, (2)Monday, (3)Tuesday, (4)Wednesday, (5)Thursday, (6)Friday, (7)Saturday", 1, 7);

    return (enWeeksDays) WeekDay;
}

string CheckWeeksDays(enWeeksDays WeekDays)
{
    switch (WeekDays)
    {
    case enWeeksDays::Sunday:
        return "Its Sunday";
    case enWeeksDays::Monday:
        return "Its Monday";
    case enWeeksDays::Tuesday:
        return "Its Tuesday";
    case enWeeksDays::Wednesday:
        return "Its Wednesday";
    case enWeeksDays::Thursday:
        return "Its Thursday";
    case enWeeksDays::Friday:
        return "Its Friday";
    case enWeeksDays::Saturday:
        return "Its Saturday";
    default:
        return "Not a valid Day";
    }
}

int main()
{
    string WeekDay = CheckWeeksDays(PrintMinueWeeksDays());

    cout << endl;
    cout << WeekDay << endl;

    return 0;
}