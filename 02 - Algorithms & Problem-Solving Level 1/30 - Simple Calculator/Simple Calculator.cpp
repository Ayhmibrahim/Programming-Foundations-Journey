#include <iostream>
#include <string>

 using namespace std;

enum enOperationType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

float ReadNumber(string Message)
{
    float Number;
    cout << Message << endl;
    cin >> Number;

    return Number;
}

enOperationType ReadOpType()
{
    char OT;

    cout << "Please enter Operation Type (+ , - , * , / )?\n";
    cin >> OT;

    return (enOperationType) OT;
}

float CalCulate(float Number1, float Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Subtract:
        return Number1 - Number2;
    case enOperationType::Multiply:
        return Number1 * Number2;
    case enOperationType::Divide:
        return Number1 / Number2;
    default:
        return Number1 + Number2;      
    }
}

int main()
{
    float Number1 = ReadNumber("Please Enter the first number?");
    float Number2 = ReadNumber("Please enter the second number?");

    enOperationType OpType = ReadOpType();

    float Calculate = CalCulate(Number1, Number2, OpType);

    cout << endl << "Result = " << Calculate << endl;

    return 0;
}