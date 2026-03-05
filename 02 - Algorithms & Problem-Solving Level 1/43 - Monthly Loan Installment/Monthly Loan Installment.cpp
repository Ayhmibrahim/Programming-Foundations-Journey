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

float MonthlyInstallment(float LoanAmount, float HowManyMonths)
{
    return LoanAmount / HowManyMonths;
}

int main()
{
    float LoanAmount = ReadPositiveNumber("Please enter Loan Amount?");
    float HowManyMonths = ReadPositiveNumber("How Many Months?");

    float Monthlyinstallment = MonthlyInstallment(LoanAmount, HowManyMonths);
    cout << endl;
    cout << "Monthly Installment = " << Monthlyinstallment << endl;

    return 0;
}