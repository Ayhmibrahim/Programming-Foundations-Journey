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

float CalCulateRemainder(float TotalBill, float TotalCashPaid)
{
    return TotalCashPaid - TotalBill;
}

int main()
{
    float TotalBill = ReadPositiveNumber("Please enter Totla Bill?");
    float TotalCashPaid = ReadPositiveNumber("Please enter Cash Piad?");

    cout << endl;
    cout << "Total Bill = " << TotalBill << endl;
    cout << "Total Cash Paid = " << TotalCashPaid << endl;

    cout << "************************\n";
    float Remainder = CalCulateRemainder(TotalBill, TotalCashPaid);
    cout << "Remainder = " << Remainder << endl;

    return 0;
}