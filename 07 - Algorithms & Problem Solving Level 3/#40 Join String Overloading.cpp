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

string JoinString(vector <string> vString, string Delim)
{
    string S1 = "";

    for (string& s : vString)
    {
        S1 = S1 + s + Delim;
    }

    return S1.substr(0, S1.length() - Delim.length());
}

string JoinString(string arrString[], short length, string Delim)
{
    string S1 = "";

    for (int i = 0; i < length; i++)
    {
        S1 = S1 + arrString[i] + Delim;
    }

    return S1.substr(0, S1.length() - Delim.length());
}

int main()
{
    vector <string> vString = { "Ayhm","Adham","Marfet","Ibrahim" };
  string arrString[] = {"Ayhm","Adham","Marfet","Ibrahim"};

    cout << "\nVector after join: \n";
    cout << JoinString(vString, " ");

    cout << "\n\nArray after join: \n";
    cout << JoinString(arrString,4, " ");


    system("pause>0");
}