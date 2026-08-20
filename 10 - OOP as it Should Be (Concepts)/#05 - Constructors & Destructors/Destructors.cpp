#include <iostream>
using namespace std;
class clsPersons
{
public:
	string FullName;
	//This is Instructor will be called when object is built.
	clsPersons()
	{
		FullName = "Mohammed Abu-Hadhoud";
		cout << "\nHi, I'm Constructor";
	}
	//This is destructor will be called when object is destroyed.
	~clsPersons()
	{
		cout << "\nHi, I'm Destructor";
	}
};
void Fun1()
{
	clsPersons Person1;
	//after exiting from function, person1 will be
	//destroyed and destructor will be called.
}
void Fun2()
{
	clsPersons* Person2 = new clsPersons;
	//always use delete whenever you use new, otherwise object
	//will remain in memory
		delete Person2;
}

int main()
{
	Fun1();
	Fun2();
	system("pause>0");
	return 0;
}