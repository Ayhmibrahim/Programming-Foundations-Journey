#include <iostream>
#include <string>
#include <cmath>

 using namespace std;

float ReadNumbers()
{
    float D;

    cout << "Please Enter D?\n";
    cin >> D;

    return D;
}

float CalculateCircleAreaByDiameter(float D)
{
    const float PI = 3.141592654;

    return (PI * pow(D, 2)) / 4;
}

void PrintResult(float Area)
{
    cout << "\nCircle Area = " << Area << endl;
}

int main()
{

    PrintResult(CalculateCircleAreaByDiameter(ReadNumbers()));

    return 0;
} 