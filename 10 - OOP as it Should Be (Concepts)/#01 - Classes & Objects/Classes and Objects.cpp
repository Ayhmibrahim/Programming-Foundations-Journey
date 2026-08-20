#include <iostream>
using namespace std;



class clsPersons
{

public:

    string FirstName;
    string LastName;

    string FullName()
    {
        return FirstName + " " + LastName;
    }

};


int main()
{
    clsPersons Person;

    Person.FirstName = "Ayhm";
    Person.LastName = "Ibrahim";

    cout << Person.FullName() << endl;


    return 0;
}