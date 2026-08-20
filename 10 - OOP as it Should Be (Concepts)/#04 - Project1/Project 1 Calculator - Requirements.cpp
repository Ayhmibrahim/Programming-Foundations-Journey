#include <iostream>
using namespace std;


class clsCalculator
{
private:
    float _Result = 0;
    float _LastNumber = 0;
    string _LastOperation ="Clear";
    float _PreviousResult = 0;
    bool _IsZero(float Number)
    {
        return (Number == 0);
    }
    
public:

    void Add(int Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Adding";
        _Result += Number;
    }

    void Subtract(int Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Subtracting";
        _Result -= Number;
    }

    void Divide(float Number)
    {
        _LastNumber = Number;

        if (_IsZero(Number))
        {
            Number = 1;
        }
        _PreviousResult = _Result;
        _LastOperation = "Dividing";
        _Result /= Number;
    }
 
    void Multiply(float Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Multiplying";
        _Result *= Number;
    }

    float GetFinalResutls()
    {
        return _Result;
    }

    void Clear()
    {
        _LastNumber = 0;
        _PreviousResult = 0;
        _LastOperation = "Clear";
        _Result = 0;
    }

    void CancelLastOperation()
    {
        _LastNumber = 0;
        _LastOperation = "Cancelling Last Operation";
        _Result = _PreviousResult;
    }

    void PrintResult()
    {
        cout << "Result ";
        cout << "Affter " << _LastOperation << " " << _LastNumber << " Is " << _Result << endl;
    }

};

int main() {

    clsCalculator Calculator1;

    Calculator1.Add(10);
    Calculator1.PrintResult();

    Calculator1.Add(15);
    Calculator1.PrintResult();

    Calculator1.Add(100);
    Calculator1.PrintResult();

    Calculator1.Divide(0);
    Calculator1.PrintResult();

    Calculator1.Multiply(5);
    Calculator1.PrintResult();

    Calculator1.Subtract(55);
    Calculator1.PrintResult();

    Calculator1.Subtract(55);
    Calculator1.PrintResult();

    Calculator1.CancelLastOperation();
    Calculator1.PrintResult();

    Calculator1.Clear();
    Calculator1.PrintResult();



    return 0;
}