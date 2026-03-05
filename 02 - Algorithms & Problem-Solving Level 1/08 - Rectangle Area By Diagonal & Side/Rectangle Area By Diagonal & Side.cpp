#include <iostream>
#include <string>
#include <cmath>

 using namespace std;

void ReadNumbers(float &A, float &D)
{
    cout << "Please Enter A?\n";
    cin >> A;

    cout << "Please Enter D?\n";
    cin >> D;
}

float RectangleAreaBySideAndDiagonal(float A, float D)
{
    return A * sqrt(pow(D, 2) - pow(A, 2));
}

void PrintResult(float Area)
{
    cout << "\nRectangle Area = " << Area << endl;
}

int main()
{
    float A, D;

    ReadNumbers(A, D);
    PrintResult(RectangleAreaBySideAndDiagonal(A, D));

    return 0;
} 