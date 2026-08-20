#include <iostream>
using namespace std;

class clsPersons
{
private:

	class clsAddress
	{
	private:
		string _AddressLine1;
		string _AddressLine2;
		string _City;
		string _Country;
	public:

		clsAddress()
		{

		}

		clsAddress(string AddressLine1, string AddressLine2, string City, string Country)
		{
			_AddressLine1 = AddressLine1;
			_AddressLine2 = AddressLine2;
			_City = City;
			_Country = Country;
		}

		void setAddressLine1(string AddressLine1)
		{
			_AddressLine1 = AddressLine1;

		}

		string AddressLine1()
		{
			return _AddressLine1;
		}

		void setAddressLine2(string AddressLine2)
		{
			_AddressLine2 = AddressLine2;
		}

		string AddressLine2()
		{
			return _AddressLine2;
		}

		void setCity(string City)
		{
			_City = City;
		}

		string City()
		{
			return _City;
		}

		void setCountry(string Country)
		{
			_Country = Country;
		}

		string Country()
		{
			return _Country;
		}

		void Print()
		{
			cout << "\nAddress:\n";
			cout << _AddressLine1 << endl;
			cout << _AddressLine2 << endl;
			cout << _City << endl;
			cout << _Country << endl;

		}

		friend class clsPersons;
	};

	string _FullName;
	clsAddress _Address;

public:

	void setFullName(string FullName)
	{
		_FullName = FullName;

	}

	string FullName()
	{
		return _FullName;
	}

	clsAddress Address = clsAddress("", "", "","");

	clsPersons(string FullName, string AddressLine1, string AddressLine2, string City, string Country)
	{
		_FullName = FullName;
		
		//initiate address class by it's constructor
		Address = clsAddress(AddressLine1, AddressLine2, City, Country);
	}


};

int main()
{
	
	clsPersons Person("Ayham Ibrahim", "Muhammad Bin Hamadah", "Al Safa Dist.", "Jeddah 23456 - 4755", "Kingdom of Saudi");

	Person.Address.Print();
}