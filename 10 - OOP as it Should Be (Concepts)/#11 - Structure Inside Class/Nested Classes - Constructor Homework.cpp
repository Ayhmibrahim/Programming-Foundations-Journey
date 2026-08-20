#include <iostream>
using namespace std;

class clsPerson
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

		friend class clsPerson;
	};

	string _FullName;
	clsAddress _Address;
	
public:
	
	

	clsPerson(string FullName,string AddressLine1, string AddressLine2, string City, string Country)
	{
		_FullName = FullName;
		_Address._AddressLine1 = AddressLine1;
		_Address._AddressLine2 = AddressLine2;
		_Address._City = City;
		_Address._Country = Country;
	}


	void setFullName(string FullName)
	{
		_FullName = FullName;

	}

	string FullName()
	{
		return _FullName;
	}

	void setAddressLine1(string AddressLine1)
	{
		_Address._AddressLine1 = AddressLine1;

	}

	string AddressLine1()
	{
		return _Address._AddressLine1;
	}

	void setAddressLine2(string AddressLine2)
	{
		_Address._AddressLine2 = AddressLine2;
	}

	string AddressLine2()
	{
		return _Address._AddressLine2;
	}

	void setCity(string City)
	{
		_Address._City = City;
	}

	string City()
	{
		return _Address._City;
	}

	void setCountry(string Country)
	{
		_Address._Country = Country;
	}

	string Country()
	{
		return _Address._Country;
	}

	void Print()
	{
		cout << "\nAddress\n";
		cout << "---------------------------------\n";
		cout << "FullName       : " << _FullName << endl;
		cout << "Address Line 1 : " << _Address.AddressLine1() << endl;
		cout << "Address Line 2 : " << _Address.AddressLine2() << endl;
		cout << "City           : " << _Address.City() << endl;
		cout << "Country        : " << _Address.Country() << endl;
		cout << "---------------------------------\n";

	}

};

int main()
{
	
	clsPerson Person("Ayham Ibrahim", "Muhammad Bin Hamadah", "Al Safa Dist.", "Jeddah 23456 - 4755", "Kingdom of Saudi");

	Person.Print();
}