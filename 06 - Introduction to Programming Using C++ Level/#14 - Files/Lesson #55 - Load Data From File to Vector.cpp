#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


void LoadDataFormFileToVector(string FileName,vector <string>& vFileContent)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);//readMod

    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            vFileContent.push_back(Line);
        }

        MyFile.close();
    }
}

int main()
{
    vector <string> vFileContent;
    LoadDataFormFileToVector("MyFile.text", vFileContent);

    for (string& Line : vFileContent)
    {
        cout << Line << endl;
    }

    return 0;
}