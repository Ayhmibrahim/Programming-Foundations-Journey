#include <iostream>
#include <string>
#include <cmath>

 using namespace std;

void ReadNumbers(float &A, float &B, float &C)
{
    cout << "Please Enter A?\n";
    cin >> A;

    cout << "Please Enter B?\n";
    cin >> B;

    cout << "Please Enter C?\n";
    cin >> C;
}

float CircleAreaByArbitaryTriangle(float A, float B, float &C)
{
    const float PI = 3.141592654;

    float P = (A + B + C) / 2;

    return PI * pow((A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C))), 2);
}

void PrintResult(float Area)
{
    cout << "\nCircle Area = " << Area << endl;
}

int main()
{
    float A, B, C;
    
    ReadNumbers(A, B, C);
    PrintResult(CircleAreaByArbitaryTriangle(A, B, C));

    return 0;
} 