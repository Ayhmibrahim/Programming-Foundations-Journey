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

float MyAbs(float Number)
{
    if (Number > 0)
        return Number;
    else
        return Number * -1;
}

int main()
{
    float Number = ReadNumber();

    cout << "\nMy abs Result : " << MyAbs(Number) << endl;
    cout << "C++ abs Result: " << abs(Number) << endl;

    return 0;
}