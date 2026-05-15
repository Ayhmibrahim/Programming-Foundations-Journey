#include <iostream>

#include "MyInputOutputLib.h";
using namespace std;


int main()
{
  
 short M = MyInput::ReadNumber();

 string Result;

 Result = (M == 0) ? "Zero\n" : ((M > 0) ? "Positive\n" : "INegative\n");

 cout << "Number is: " << Result;

    return 0;
}