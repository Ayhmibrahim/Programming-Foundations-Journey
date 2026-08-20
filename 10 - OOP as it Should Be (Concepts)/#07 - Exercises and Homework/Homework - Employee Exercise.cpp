#include <iostream>
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
	string _Department;
	float _Salary;


public:
	clsPersons(short ID, string FirstName, string LastName, string Title, string Email, string Phone, string Department, float Salary)
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Title = Title;
		_Department = Department;
		_Email = Email;
		_Phone = Phone;
		_Salary = Salary;

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

	void setTitle(string Title)
	{
		_Title = Title;
	}

	string Title()
	{
		return _Title;
	}

	void setDepartment(string Department)
	{
		_Department = Department;
	}

	string Department()
	{
		return _Department;
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
	void setSalary(float Salary)
	{
		_Salary = Salary;
	}

	float Salary()
	{
		return _Salary;
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
		cout << "Department: " << Department() << endl;
		cout << "Salary    : " << Salary() << endl;
		cout << "_________________________________\n";
	}

	~clsPersons()
	{
		cout << "\tEnd Person." << endl;
	}

};

int main()
{

	clsPersons Person1(10, "Ayhm", "Ibrahim","Developer", "Ayhmalmwmra@gmail.com", "0569112070", "IT Department", 3000);
	Person1.Print();

	Person1.SendEmail("Hi", "How Are You?");
	Person1.SendSMS("How Are You?");

	system("pause>0");

	return 0;

}