#include <iostream>
using namespace std;

class clsAddress
{
private:
    string _AddressLine1;
    string _AddressLine2;
    string _POBox;
    string _ZipCode;

public:

    clsAddress(string AddressLine1, string AddressLine2, string POBox, string ZipCode)
    {
        _AddressLine1 = AddressLine1;
        _AddressLine2 = AddressLine2;
        _POBox = POBox;
        _ZipCode = ZipCode;

    }

    //Copy Constructor
    clsAddress(clsAddress& Old_obj)
    {

        _AddressLine1 = AddressLine1();
        _AddressLine2 = AddressLine2();
        _POBox = POBox();
        _ZipCode = ZipCode();
    }

        void setAddressLine1(string AddressLine1)
    {
        _AddressLine1 = AddressLine1;
    }

    string AddressLine1()
    {
        return _AddressLine1;
    }

    void setAddressLine2(string AddressLine2)
    {
        _AddressLine2 = AddressLine2;
    }

    string AddressLine2()
    {
        return _AddressLine2;
    }

    void setPOBox(string POBox)
    {
        _POBox = POBox;
    }

    string POBox()
    {
        return _POBox;
    }

    void setZipCode(string ZipCode)
    {
        _ZipCode = ZipCode;
    }

    string ZipCode()
    {
        return _ZipCode;
    }

    void Print()
    {
        cout << "\nAddress Details:\n";
        cout << "-------------------------\n";
        cout << "AddressLine1: " << AddressLine1() << endl;
        cout << "AddressLine2: " << AddressLine2() << endl;
        cout << "POBox       : " << POBox() << endl;
        cout << "ZipCode     : " << ZipCode() << endl;
    }

};

int main() {


    clsAddress Address1("Muhammad Ibn Hammadi", "Al-Safa", "Jeddah", "23456");
    Address1.Print();

    clsAddress Address2 = Address1;
    Address2.Print();

    return 0;
}