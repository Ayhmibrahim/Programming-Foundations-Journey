#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char  ReadChar()
{
    char C1;
    cout << "Please Enter Your Charccter?\n";
   cin>>C1;
    return C1;
}

string LowerFirstLetterOfEachWord(string S1)
{
    bool IsFirstLetter = true;
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && IsFirstLetter) {

            S1[i] = tolower(S1[i]);
        }
        IsFirstLetter = (S1[i] == ' ' ? true : false);
    }

    return S1;
}

char InvertCharccterCase(char C1)
{

    return (isupper(C1)) ? tolower(C1) : toupper(C1);

   
}


int main()
{
    char C1 = ReadChar();
    
    cout << "Char after inverting case:\n";
    C1 = InvertCharccterCase(C1);
    cout << C1;

    return 0;
}