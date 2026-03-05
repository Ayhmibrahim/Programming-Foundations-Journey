#include <iostream>
#include <string>

 using namespace std;

void ReadNumbers(int &num1, int &num2, int &num3)
{
    cout << "Please Enter Number 1\n";
    cin >> num1;

    cout << "Please Enter Number 2\n";
    cin >> num2;

    cout << "Please Enter Number 3\n";
    cin >> num3;
}

int MaxOf3Numbers(int num1, int num2, int num3)
{
    if (num1 > num2)
        if (num1 > num3)
            return num1;
        else
            return num3;
    
    else
        if (num2 > num3)
            return num2;
        else
            return num3;
}

void PrintResults(int Max)
{

    cout << "\n The Maximum Number is: " << Max << endl;   

}
 
int main()
{
    int num1, num2, num3;

    ReadNumbers(num1, num2, num3);
    PrintResults(MaxOf3Numbers(num1, num2, num3));

    return 0;
}