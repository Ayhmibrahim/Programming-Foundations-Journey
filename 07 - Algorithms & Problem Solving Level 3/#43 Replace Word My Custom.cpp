#include <iostream>
#include <string>
#include <vector>
using namespace std;

string  ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

vector <string> SplitString(string S1, string Delim)
{
    vector <string> vString;

    short pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != std::string::npos) {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

string JoinString(vector <string> vString, string Delim)
{
    string S1 = "";

    for (string& s : vString)
    {
        S1 = S1 + s + Delim;
    }

    return S1.substr(0, S1.length() - Delim.length());
}

string ChangeCharToLowerCase(string S1)
{

    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}


string ReplaceWordCustom(string S1, string
    StringToReplace, string sRepalceTo,bool MatchCase = true)
{
    vector <string> vString = SplitString(S1, " ");

    for (string& word : vString)
    {
        if (MatchCase)
        {
            if (word == StringToReplace)
            {
                word = sRepalceTo;
            }
        }
        else
        {
            if (ChangeCharToLowerCase(word) == ChangeCharToLowerCase(StringToReplace))
            {
                word = sRepalceTo;
            }
        }
        
    }

    return JoinString(vString," ");
}


int main()
{
    
}