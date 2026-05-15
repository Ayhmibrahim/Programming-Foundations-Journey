#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void LoadDataFormFileToVector(string FileName, vector <string>& vFileContent)
{
    fstream MyFile;
    MyFile.open("MyFile.txt", ios::in);//readMod

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

void SaveVectorToFile(string FileName, vector <string> vFileContent)
{
    fstream MyFile;
    MyFile.open("MyFile.txt", ios::out);

    if (MyFile.is_open())
    {
        for (string& Line : vFileContent)
        {
            if (Line != "")
            {
                MyFile << Line << endl;
            }
        }

        MyFile.close();
    }
}

void DeleteRecordFromFile(string FileName, string Record)
{
    vector <string> vFileContent;
    LoadDataFormFileToVector(FileName, vFileContent);

    for (string& Line : vFileContent)
    {
        if (Line == Record)
        {
            Line = "";
        }
    }

    SaveVectorToFile(FileName, vFileContent);
}

void PrintFileContenet(string FileName)
{
    fstream MyFile;
    MyFile.open("MyFile.txt", ios::in);//readMod

    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {

            cout << Line << endl;

        }

        MyFile.close();
    }

}

int main()
{
    cout << "File Content Before Delete.\n";
    PrintFileContenet("MyFile.text");

    DeleteRecordFromFile("MyFile.text","Ali");

    cout << "\nFile Content After Delete.\n";
    PrintFileContenet("MyFile.text");

    return 0;
}