#include <iostream>
#include <string>

 using namespace std;

void ReadNumbers(float &Length, float &Width)
{
    cout << "Please Enter Length?\n";
    cin >> Length;

    cout << "Please Enter Width?\n";
    cin >> Width;
}

float CalculateRectangleArea(float Length, float Width)
{
    return Length * Width;
}

void PrintResult(float Area)
{
    cout << "\nRectangle Area = " << Area << endl;
}

int main()
{
    float Length, Width;

    ReadNumbers(Length, Width);
    PrintResult(CalculateRectangleArea(Length, Width));

    return 0;
} 