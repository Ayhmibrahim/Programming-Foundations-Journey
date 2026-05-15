#include <iostream>
#include <string>
using namespace std;

enum enWhatToCount
{
    CapitalLetters = 0 , SmallLetters = 1 , All=2
};

string  ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

char  ReadChar()
{
    char C1;
    cout << "\nPlease Enter Your Charccter?\n";
    cin >> C1;
    return C1;
}

int CountLetters(string S1,char C1)
{
    int Counter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i]== C1)
        {
            Counter++;
        }
    }

    return Counter;

}

int main()
{

    string S1 = ReadString();
    char C1 = ReadChar();
   
    cout << "\nLetter '" << C1 << "' Count = " << CountLetters(S1, C1);

    system("pause>0");
    return 0;
}