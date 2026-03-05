#include <iostream>
#include <string>

 using namespace std;

int ReadTotalSalse()
{
    int TotalSalse;
    cout << "Please Enter Total Salse?\n";
    cin >> TotalSalse;

    return TotalSalse;
}

float GetComissionPercentage(int TotalSalse)
{
    if (TotalSalse > 1000000)
        return 0.01;
    else if (TotalSalse > 500000)
        return 0.02;
    else if (TotalSalse > 10000)
        return 0.03;
    else if (TotalSalse >= 50000)
        return 0.05;
    else
        return 0.00;
}

float CalculateTotalComission(float TotalSalse)
{
    return GetComissionPercentage(TotalSalse) * TotalSalse;
}

int main()
{
    int TotalSalse = ReadTotalSalse();

    float ComissionPercentage = GetComissionPercentage(TotalSalse);
    float TotalComission = CalculateTotalComission(TotalSalse);

    cout << endl << "Comission Percentage = " << ComissionPercentage << endl;
    cout << endl << "Total Comission = " << TotalComission << endl;
    
    return 0;
}