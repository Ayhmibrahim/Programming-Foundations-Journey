#include <iostream>
#include <string>

 using namespace std;

void ReadNumbers(int &num1, int &num2)
{
    cout << "Please Enter Number 1?\n";
    cin >> num1;

    cout << "Please Enter Number 2?\n";
    cin >> num2;    
}

void Swap(int &num1, int &num2)
{
    int Temp;

    Temp = num1;
    num1 = num2;
    num2 = Temp;
}

void PrintNumbers(int num1, int num2)
{
    cout << "\nNumber1 = " << num1 << endl;
    cout << "Number2 = " << num2 << endl;
}

int main()
{
    int num1, num2;

    ReadNumbers(num1, num2);
    PrintNumbers(num1, num2);
    Swap(num1, num2);
    PrintNumbers(num1, num2);

    return 0;
}