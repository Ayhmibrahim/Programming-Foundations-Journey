#include <iostream>
#include <cmath>


 using namespace std; 

float ReadNumber()
{
    float Number;
    cout << "\nPlease Enter a Number?\n";
    cin >> Number;

    return Number;
}     

float GetFractionPart(float Number)
{
    return Number - (int)Number;
}

int MyFloor(float Number)
{
    if (abs(GetFractionPart(Number)) > 0)
    {
        if (Number > 0)
            return (int)Number;
        else
            return (int)Number - 1;
    }
    else
        return Number;
}

int main()
{
    float Number = ReadNumber();

    cout << "\nMy Floor Result : " << MyFloor(Number) << endl;
    cout << "C++ Floor Result: " << floor(Number) << endl;

    return 0;
}