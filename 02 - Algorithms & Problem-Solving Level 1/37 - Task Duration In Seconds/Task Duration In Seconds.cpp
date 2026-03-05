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

stTaskDuration ReadTaskDuration()
{
    stTaskDuration TaskDuration;

    TaskDuration.NumberOfDays = ReadPositiveNumber("Please enter Number Of Days?");
    TaskDuration.NumberOfHours = ReadPositiveNumber ("Please enter Number Of Hours?");
    TaskDuration.NumberOfMinutes = ReadPositiveNumber("Please enter Number Of Minutes?");
    TaskDuration.NumberOfSeconds = ReadPositiveNumber("Please enter Number Of Seconds");

    return TaskDuration;
}

int taskDurationInSeconds(stTaskDuration TaskDuration)
{
    int DurationInSeconds = 0;

    DurationInSeconds = TaskDuration.NumberOfDays * 24 * 60 * 60;
    DurationInSeconds += TaskDuration.NumberOfHours * 60 * 60;
    DurationInSeconds += TaskDuration.NumberOfMinutes * 60;
    DurationInSeconds += TaskDuration.NumberOfSeconds;

    return DurationInSeconds;
}

int main()
{
    int TaskDuration = taskDurationInSeconds(ReadTaskDuration());

    cout << "\nTask Duration In Seconds: " << TaskDuration << endl;

    return 0;
}