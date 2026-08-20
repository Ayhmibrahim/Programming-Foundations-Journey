#include<iostream>
using namespace std;


class clsPerson {


	struct stAddress
	{
		string AddressLine1;
		string AddressLine2;
		string City;
		string Country;
	};

public:
	string FullName;
	stAddress Address;

	clsPersonٍ()
	{
		FullName = "Ayham Ibrahim";
		Address.AddressLine1 = "Building 22";
		Address.AddressLine2 = "Al Safa Street";
		Address.City = "Jeedah";
		Address.Country = "Saudi";
	}

	void PrintAddress()
	{
		cout << "\nAddress:\n";
		cout << Address.AddressLine1 << endl;
		cout << Address.AddressLine2 << endl;
		cout << Address.City << endl;
		cout << Address.Country << endl;
	}

};


int main()
{
	clsPersons Person1;
	Person1.PrintAddress();
	system("pause>0");
	return 0;
}