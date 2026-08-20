#include <iostream>
using namespace std;



class clsPerson
{
private:
    //هذا فقط داخل الكلاس وماظهر للمطور او للكلاسات الثانيه
    int Variable1 = 5;

    int Function1()
    {
        return 40;
    }

protected:
    //هذا اقدر اظهره و اورثه لاي كلاس اخر خارج كلاس البيرسون لكن مايظهر للمطور او يعدل عليه 
    int Variable2 = 100;
    int Function2()
    {
        return 50;
    }

public:
    
    string FirstName;
    string LastName;

    string FullName()
    {
        return FirstName + " " + LastName;
    }

    int Function3()
    {
        return Function1() * Variable1 * Variable2;
    }

};


int main() {


    clsPerson Person1;

    Person1.FirstName = "Ayhm";
    Person1.LastName = "Ibrahim";
    cout << "Person1: " << Person1.FullName() << endl;
    cout << Person1.Function3() << endl;

    return 0;
}