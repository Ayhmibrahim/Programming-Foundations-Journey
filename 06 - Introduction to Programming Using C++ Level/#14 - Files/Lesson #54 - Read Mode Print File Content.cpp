#include <fstream>
#include <iostream>
#include <string>
using namespace std;


void PrintFileContenet(string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);//readMod

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
    PrintFileContenet("MyFile.text");

    return 0;
}