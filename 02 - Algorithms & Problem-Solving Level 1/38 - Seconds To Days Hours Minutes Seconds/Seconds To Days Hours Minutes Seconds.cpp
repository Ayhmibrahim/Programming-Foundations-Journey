#include <iostream>
#include <string>

 using namespace std;

struct stTaskDuration
{
    int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;
};

int ReadPositiveNumber(string Message)
{
    int Number;

    do
    {
        cout << Message << endl;
        cin >> Number;

    } while (Number <= 0);

    return Number;
}

stTaskDuration SecondsToTaskDuration(int TotalSeconds)
{
    stTaskDuration TaskDuration;
    const int SecondsPerDay = 24 * 60 * 60;
    const int SecondsPerHours = 60 * 60;
    const int SecondsPerMinutes = 60;

    int Remainder = 0;
    TaskDuration.NumberOfDays = TotalSeconds / SecondsPerDay;
    Remainder = TotalSeconds % SecondsPerDay;
    TaskDuration.NumberOfHours = Remainder / SecondsPerHours;
    Remainder = Remainder % SecondsPerHours;
    TaskDuration.NumberOfMinutes = Remainder / SecondsPerMinutes;
    Remainder = Remainder % SecondsPerMinutes;
    TaskDuration.NumberOfSeconds = Remainder;

    return TaskDuration;
}

void PrintTaskDuration(stTaskDuration TaskDuration)
{
    cout << endl;
    cout << TaskDuration.NumberOfDays << ":" << TaskDuration.NumberOfHours << ":" <<
    TaskDuration.NumberOfMinutes << ":" << TaskDuration.NumberOfSeconds << endl;
}
int main()
{
    int TotalSeconds = ReadPositiveNumber("Please enter Number Of Seconds?");
    PrintTaskDuration(SecondsToTaskDuration(TotalSeconds));

    return 0;
}