#include <iostream>
#include "clsPerson.h";
using namespace std;

class clsPersons
{
private:
	short _ID;
	string _FirstName;
	string _LastName;
	string _Title;
	string _Email;
	string _Phone;


public:
	clsPersons(short ID, string FirstName, string LastName, string Email, string Phone)
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Phone = Phone;
	}

	short ID()
	{
		return _ID;
	}

	void setFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	string FirstName()
	{
		return _FirstName;
	}

	void setLastName(string LastName)
	{
		_LastName = LastName;
	}

	string LastName()
	{
		return _LastName;
	}

	void setEmail(string Email)
	{
		_Email = Email;
	}

	string Email()
	{
		return _Email;
	}

	void setPhone(string Phone)
	{
		_Phone = Phone;
	}

	string Phone()
	{
		return _Phone;
	}

	string FullName()
	{
		return FirstName() + " " + LastName();
	}

	void SendEmail(string Subject, string Body)
	{
		cout << "\nThe follwing message sent successfully to email: " << Email() << endl;

		cout << "Subject: " << Subject << endl;
		cout << "Body: " << Body << endl;
	}

	void SendSMS(string TextMessage)
	{
		cout << "\nThe follwing message sent successfully to Phone: " << Phone() << endl;

		cout << TextMessage << endl;
	}

	void Print()
	{
		cout << "\nInfo:\n";
		cout << "_________________________________\n";
		cout << "ID        : " << ID() << endl;
		cout << "FirstName : " << FirstName() << endl;
		cout << "LastName  : " << LastName() << endl;
		cout << "Full Name : " << FullName() << endl;
		cout << "Email     : " << Email() << endl;
		cout << "Phone     : " << Phone() << endl;
		cout << "_________________________________\n";
	}

	~clsPersons()
	{
		cout << "\tEnd Person." << endl;
	}

};

int main()
{

	clsPerson PersinOne(10, "Ayhm", "Ibrahim", "Ayhmalmwmra@gmail.com", "0569112070");

	PersinOne.SendSMS("You");

	clsPersons Person1(10, "Ayhm", "Ibrahim", "Ayhmalmwmra@gmail.com", "0569112070");
	Person1.Print();

	Person1.SendEmail("Hi", "How Are You?");
	Person1.SendSMS("How Are You?");

	system("pause>0");

	return 0;

}