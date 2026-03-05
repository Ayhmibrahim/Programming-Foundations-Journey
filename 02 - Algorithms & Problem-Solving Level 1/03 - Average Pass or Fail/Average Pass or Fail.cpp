#include <iostream>
#include <string>

 using namespace std;

enum enPassFail{ Pass = 1, Fail = 2 };

void ReadMarks(int Marks[3])
{
    cout << "Please Enter Marks 1?\n";
    cin >> Marks[0];

    cout << "Please Enter Marks 2?\n";
    cin >> Marks[1];

    cout << "Please Enter Marks 3?\n";
    cin >> Marks[2];
}

int SumOf3Marks(int Marks[3])
{
    return Marks[0] + Marks[1] + Marks[2];
}

float SumAverageMarks(int Marks[3])
{
    return (float) SumOf3Marks(Marks) / 3;
}

enPassFail CheakAverage(float Average)
{
    if (Average >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}

void PrintAvrage(float Average)
{
    cout << "\n The Average is: " << Average << endl;

    if (CheakAverage(Average) == enPassFail::Pass)
        cout << "\n You Passed" << endl;
    else
        cout << "\n You Faild" << endl;
}

int main()
{
    int Marks[3];

    ReadMarks(Marks);
    PrintAvrage(SumAverageMarks(Marks));

    return 0;
}