#include <iostream>
using namespace std;


float GetFractionPart(float Number)
{
    return Number - (int)Number;
}

float MyABS(float Number)
{
    if (Number > 0)
        return Number;
    else
        return Number * -1;
}

int MyCeil(float Number)
{
    

    if (MyABS(GetFractionPart(Number)) > 0)

    {
        if (Number > 0)

            return (int)Number+1;

        else
            return (int)Number;

    }

    else
    
        return Number;
	

}

float ReadNumber()
{
    float Number;

    cout << "Please enter a number? ";
    cin >> Number;

    return Number;
}

int main()
{
    float Number = ReadNumber();

    cout << "My Ceil Result : " << MyCeil(Number) << endl;

    cout << "C++ Ceil Result: " << ceil(Number) << endl;

    return 0;
}