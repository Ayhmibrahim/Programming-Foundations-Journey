#include <iostream>
#include <string>
#include <cctype>
using namespace std;



string  ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

char InvertCharccterCase(char C1)
{

    return (isupper(C1)) ? tolower(C1) : toupper(C1);


}

string InvertAllStringLettersCase(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = InvertCharccterCase(S1[i]);
    }
    return S1;
}

int main()
{
    string S1 = ReadString();
    cout << "\nString after Inverting All Letters Case:\n";
    S1 = InvertAllStringLettersCase(S1);
    cout << S1 << endl;
    system("pause>0");
}