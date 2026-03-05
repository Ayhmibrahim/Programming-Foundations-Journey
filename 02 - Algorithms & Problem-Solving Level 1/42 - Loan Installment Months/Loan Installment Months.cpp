#include <iostream>
#include <string>

 using namespace std;

float ReadPositiveNumber(string Message)
{
    float Number;

    do
    {
        cout << Message << endl;
        cin >> Number;

    } while (Number <= 0);

    return Number;
}

float CalculateMonth(float LoanAmount, float MonthlyPayment)
{
    return LoanAmount / MonthlyPayment;
}

int main()
{
    float LoanAmount = ReadPositiveNumber("Please enter Loan Amount?");
    float MonthlyPayment = ReadPositiveNumber("Please enter Monthly Payment");

    float CalculateMonthly = CalculateMonth(LoanAmount, MonthlyPayment);
    cout << endl;
    cout << CalculateMonthly << " Months" << endl;

    return 0;
}