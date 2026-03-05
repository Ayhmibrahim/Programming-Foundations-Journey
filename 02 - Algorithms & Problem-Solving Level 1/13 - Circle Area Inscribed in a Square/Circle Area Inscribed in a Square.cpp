#include <iostream>
#include <string>
#include <cmath>

 using namespace std;

float ReadNumbers()
{
    float A;

    cout << "Please Enter A?\n";
    cin >> A;

    return A;
}

float CircleAreaInscribedInSquare(float A)
{
    const float PI = 3.141592654;

    return (PI * pow(A, 2)) / 4;
}

void PrintResult(float Area)
{
    cout << "\nCircle Area = " << Area << endl;
}

int main()
{

    PrintResult(CircleAreaInscribedInSquare(ReadNumbers()));

    return 0;
} 