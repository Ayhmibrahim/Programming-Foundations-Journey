#include <iostream>
#include <string>
using namespace std;

char  ReadChar()
{
    char C1;
    cout << "\nPlease Enter Your Charccter?\n";
    cin >> C1;
    return C1;
}

bool IsVowel(char C1)
{
    C1 = towlower(C1);

    return ((C1 == 'a') || (C1 == 'e') || (C1 == 'i') || (C1 == 'o') || (C1 == 'u'));
}

int main()
{

    char C1 = ReadChar();
    if (IsVowel(C1))
        cout << "\nYES Letter \'" << C1 << "\' is vowel";
    else
        cout << "\nNo Letter \'" << C1 << "\' is NOT vowel";
    
    system("pause>0");
}