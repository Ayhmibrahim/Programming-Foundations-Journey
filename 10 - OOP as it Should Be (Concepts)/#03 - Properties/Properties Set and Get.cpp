#include <iostream>
using namespace std;



class clsPersons
{
private:
    string _FirstName;
    string _LastName;
public:

    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    string FirstName()
    {
        return _FirstName;
    }

    void setLastName(string LastName)
    {
        _LastName = LastName;
    }

    string LastName()
    {
        return _LastName;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }


};


int main() {


    clsPersons Person1;

    Person1.setFirstName("Ayhm");
    Person1.setLastName("Ibrahim");

    cout << "First Name: " << Person1.FirstName() << endl;
    cout << "Last Name: " << Person1.LastName() << endl;
    cout << "Full Name: " << Person1.FullName() << endl;

    system("pause>0");

    return 0;
}