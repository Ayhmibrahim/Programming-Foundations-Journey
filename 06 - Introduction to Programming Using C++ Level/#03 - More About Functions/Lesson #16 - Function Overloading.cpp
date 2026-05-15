#include <iostream>
using namespace std;

double MySum2DuobleNumbers(double a, double b)
{
    return (a + b);
}

int MySum2IntgerNumbers(int a, int b)
{
    return (a + b);
}

int MySum3IntgerNumbers(int a, int b,int c)
{
    return (a + b + c);
}

int MySum4IntgerNumbers(int a, int b,int c,int d)
{
    return (a + b + c + d);
}

int main()
{
    cout << "Sum of 2 Intger Numbers: " << MySum2IntgerNumbers(10, 20) << endl;
    cout << "Sum of 2 Duoble Numbers: " << MySum2DuobleNumbers(10.1, 20.1) << endl;
    cout << "Sum of 3 Intger Numbers: " << MySum3IntgerNumbers(10, 20, 30) << endl;
    cout << "Sum of 4 Intger Numbers: " << MySum4IntgerNumbers(10, 20, 30, 40) << endl;


    return 0;
}