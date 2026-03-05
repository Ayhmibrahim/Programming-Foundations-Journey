#include <iostream>
#include <string>
#include <cmath>

 using namespace std;

float ReadCireumference()
{
    float L;

    cout << "Please Enter The Cireumference L?\n";
    cin >> L;

    return L;
}

float CircleAreaByCireumference(float L)
{
    const float PI = 3.141592654;

    return pow(L, 2) / (4 * PI);
}

void PrintResult(float Area)
{
    cout << "\nCircle Area = " << Area << endl;
}

int main()
{

    PrintResult(CircleAreaByCireumference(ReadCireumference()));

    return 0;
} 