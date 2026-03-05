#include <iostream>
#include <string>

 using namespace std;

enum enPassFail { Pass = 1, Fail = 2 }; 

int ReadMark()
{
    int Mark;
    cout << "Please Enter Your Mark?\n";
    cin >> Mark;

    return Mark;
}

enPassFail CheckMark(int Mark)
{
    if (Mark >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}

void PrintMark(int Mark)
{
    if (CheckMark(Mark) == enPassFail::Pass)
        cout << "\n You Passd" << endl;
    else
        cout << "\n You Faild" << endl;  
}

int main()
{
    PrintMark(ReadMark());

    return 0;
}