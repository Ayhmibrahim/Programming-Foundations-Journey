

#include <iostream>
#include<fstream>

using namespace std;

int main()
{
	fstream MyFile;

	MyFile.open("MyFile.text", ios::out); //Write Mode

	if (MyFile.is_open())
	{



		MyFile << "Mohammed\n";
		MyFile << "Fadi\n";
		MyFile << "Lama\n";

	}

	return 0;
}