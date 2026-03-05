#include <iostream>
#include <string>

 using namespace std;

float ReadPositiveNumber(string Message)
{
    float BillValue;
    
    do
    {
        cout << Message << endl;
        cin >> BillValue;

    } while (BillValue <= 0);

    return BillValue;
}

float totalBillAfterServiceAndTax(float BillValue)
{
    BillValue *= 1.1;
    BillValue *= 1.16;
    
    return BillValue;
}

int main()
{
    float BillValue = ReadPositiveNumber("Please enter Bill Value?");

    cout << endl;
    cout << "Total Bill Value = " << BillValue << endl;

    float TotalBillValue = totalBillAfterServiceAndTax(BillValue);

    cout << "**************************\n";
    cout << "Total Bill After Service Fee and Sales Tax = " << TotalBillValue << endl;

    return 0;
}

