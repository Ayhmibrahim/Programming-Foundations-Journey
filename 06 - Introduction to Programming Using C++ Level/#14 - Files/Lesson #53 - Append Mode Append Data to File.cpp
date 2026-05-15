

#include <iostream>
#include<fstream>

using namespace std;

int main()
{
	fstream MyFile;

	MyFile.open("MyFile.text", ios::out | ios::app); //Write Mode

	if (MyFile.is_open())
	{

		MyFile << "Hi, this is a new line\n";
		MyFile << "Hi, this is another new line\n";
		MyFile.close();

	}

	return 0;
}