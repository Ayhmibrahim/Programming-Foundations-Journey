#include <iostream>
#include <string>
#include <cmath>

 using namespace std;

float ReadNumbers()
{
    float r;

    cout << "Please Enter R?\n";
    cin >> r;

    return r;
}

float CalculateCircleArea(float R)
{
    const float PI = 3.141592654;

    return PI * pow(R, 2);
}

void PrintResult(float Area)
{
    cout << "\nCircle Area = " << Area << endl;
}

int main()
{

    PrintResult(CalculateCircleArea(ReadNumbers()));

    return 0;
} 