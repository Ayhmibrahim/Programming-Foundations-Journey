

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void WriteDataToFIle(fstream& MyFile , string NameFile)
{
	MyFile.open(NameFile, ios::out| ios::app); //Write Mode
	if (MyFile.is_open())
	{
		MyFile << "Hi, My names: Ayhm Ibrahim\n";
		MyFile << "My Ages = 22\n";
		MyFile << "My Country = Yemen\n";
		MyFile << "Salary = 2500 Ryal\n";

		MyFile.close();	
	}
	
}

void LoadDataFromFileToVector(string& FileName, vector <string>& vFileContent)
{
	fstream File;	
	File.open(FileName, ios::in);//readMod

	if (File.is_open())
	{
		string Line;

		while (getline(File, Line))
		{
			vFileContent.push_back(Line);
		}

		File.close();
	}
}
int main()
{
	fstream MyFile;
	string FileName;
	cout << "Enter File Name and .?: ";
	cin >> FileName;
	FileName += ".txt";

	WriteDataToFIle(MyFile, FileName);

	vector <string> vFileContent;

	LoadDataFromFileToVector(FileName, vFileContent);

	for (string Line : vFileContent)
	{
		cout << Line << endl;
	}

	return 0;
}