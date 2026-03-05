#include <iostream>
#include <string>
#include <cmath>

 using namespace std;

void ReadNumbers(float &A, float &B)
{
    cout << "Please Enter A?\n";
    cin >> A;

    cout << "Please Enter B?\n";
    cin >> B;
}

float CircleAreaByIsosclelesTriangle(float A, float B)
{
    const float PI = 3.141592654;

    return (PI * pow(B, 2)) / 4 * ((2 * A - B) / (2 * A + B));
}

void PrintResult(float Area)
{
    cout << "\nCircle Area = " << Area << endl;
}

int main()
{
    float A, B;
    
    ReadNumbers(A, B);
    PrintResult(CircleAreaByIsosclelesTriangle(A, B));

    return 0;
} 