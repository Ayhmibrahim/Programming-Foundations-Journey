#include <iostream>
#include <cmath>

 using namespace std;

void ReadNumber(int &num1, int &num2, int &num3)
{
    cout << "Please enter Number1?\n";
    cin >> num1;

    cout << "Please enter Number2?\n";
    cin >> num2;

    cout << "Please enter Number3?\n";
    cin >> num3;

}

int SumNumbers(int num1, int num2, int num3)
{
    return num1 + num2 + num3;
}

void PrintResult(int Total)
{
    cout << "\n The Total Sum of numbers is: " << Total << endl;
}

int main()
{
    int num1, num2, num3;
    
    ReadNumber(num1, num2, num3);
    PrintResult(SumNumbers(num1, num2, num3));

    return 0;
}