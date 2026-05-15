#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    time_t t;
    time(&t);
    // Store the current time in seconds since 1/1/1970 (Epoch)
    // Equivalent alternatives: t = time(NULL); t = time(0); t = time(nullptr);

    char* dateTime = ctime(&t);
    // Convert the time in seconds to a C-style string (local time)

    cout << "Local date and time is : " << dateTime << endl;

    tm* gmtm = gmtime(&t);
    // Convert the time in seconds to a pointer to a tm struct
    // representing Coordinated Universal Time (UTC)


    dateTime = asctime(gmtm);
    // Convert the tm struct to a readable string

    cout << "UTC date and time is : " << dateTime << endl;

    return 0;
}