#include <iostream>
#include <string>

 using namespace std;

int ReadNumber()
{
    int N;
    cout << "Please Enter a Number\n";
    cin >> N;

    return N;
}

void PowerOfE2E3E4(int Number)
{
    int a, b, c;

    a = Number * Number;
    b = Number * Number * Number;
    c = Number * Number * Number * Number;

    cout << a << " " << b << " " << c << endl; 
}

int main()
{
    PowerOfE2E3E4(ReadNumber());

    return 0;
}