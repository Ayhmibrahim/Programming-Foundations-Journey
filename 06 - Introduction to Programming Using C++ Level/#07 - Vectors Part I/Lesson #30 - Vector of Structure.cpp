#include <iostream>
#include<vector>

using namespace std;

struct stEmployee
{
	string FirstName;
	string LastName;
	string JobTitle;
	float  Salary;
};


int main()
{
	vector <stEmployee> vEmployees;

	stEmployee tempEmployee;

	tempEmployee.FirstName = "Ayhm";
	tempEmployee.LastName = "Ibrahim";
	tempEmployee.JobTitle = "Hr-AI";
	tempEmployee.Salary = 2500;

	vEmployees.push_back(tempEmployee);

	tempEmployee.FirstName = "Saltan";
	tempEmployee.LastName = "Idrosay";
	tempEmployee.JobTitle = "Hr";
	tempEmployee.Salary = 3000;

	vEmployees.push_back(tempEmployee);

	tempEmployee.FirstName = "Mohammed";
	tempEmployee.LastName = "Dimmes";
	tempEmployee.JobTitle = "Operations Manager";
	tempEmployee.Salary = 12000;

	vEmployees.push_back(tempEmployee);

	cout << "Employees Compnay\n\n";

	for (stEmployee &Employee : vEmployees)
	{
		cout << "FirstName: " <<Employee.FirstName<< endl; 
		cout << "LastName : " <<Employee.LastName << endl;
		cout << "Jop Title: " <<Employee.JobTitle << endl;
		cout << "Salary   : " <<Employee.Salary << endl;

		cout << "--------------------------------\n";

		cout << endl;
	}
	cout << endl;
}