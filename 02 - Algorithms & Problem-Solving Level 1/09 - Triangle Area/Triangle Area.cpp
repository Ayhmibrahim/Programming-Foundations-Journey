#include <iostream>
#include <string>
#include <cmath>

 using namespace std;

void ReadNumbers(float &A, float &H)
{
    cout << "Please Enter A?\n";
    cin >> A;

    cout << "Please Enter H?\n";
    cin >> H;
}

float CalculateTriangleArea(float A, float H)
{
    return A/2 * H;
}

void PrintResult(float Area)
{
    cout << "\nTriangle Area = " << Area << endl;
}

int main()
{
    float A, H;

    ReadNumbers(A, H);
    PrintResult(CalculateTriangleArea(A, H));

    return 0;
} 