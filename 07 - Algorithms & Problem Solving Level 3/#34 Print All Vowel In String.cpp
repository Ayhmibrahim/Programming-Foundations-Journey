#include <iostream>
#include <string>
using namespace std;

string  ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

bool IsVowel(char C1)
{
    C1 = towlower(C1);

    return ((C1 == 'a') || (C1 == 'e') || (C1 == 'i') || (C1 == 'o') || (C1 == 'u'));
}

void CountLetters(string S1)
{
    cout << "\nVowels in string are: ";
    for (int i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
        {
            cout << S1[i] << "  ";
        }
    }
}

int main()
{
    string S1 = ReadString();

    CountLetters(S1);


    system("pause>0");
}