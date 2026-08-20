#include <iostream>
using namespace std;

// الكلاس الأساسي (Base Class)
class clsPerson
{
public:

	// virtual تعني:
	// استخدم الدالة المناسبة حسب نوع الكائن الحقيقي
	// وليس حسب نوع المؤشر فقط.
	virtual void Print()
	{
		cout << "Hi, i'm a person!\n";
	}
};

// كلاس موظف يرث من clsPerson
class clsEmployee : public clsPerson
{
public:

	// إعادة تعريف الدالة Print الخاصة بالأب
	void Print()
	{
		cout << "Hi, I'm an Employee\n";
	}
};

// كلاس طالب يرث من clsPerson
class clsStudent : public clsPerson
{
public:

	// إعادة تعريف الدالة Print الخاصة بالأب
	void Print()
	{
		cout << "Hi, I'm a student\n";
	}
};

int main()
{
	// إنشاء كائن من الموظف
	clsEmployee Emoloyee1;

	// إنشاء كائن من الطالب
	clsStudent Steudent1;

	// استدعاء مباشر للدوال
	Emoloyee1.Print();
	Steudent1.Print();

	cout << "-----------------\n";

	// مؤشر من نوع الأب يشير إلى كائن موظف
	clsPerson* Person1 = &Emoloyee1;

	// مؤشر من نوع الأب يشير إلى كائن طالب
	clsPerson* Person2 = &Steudent1;

	// بسبب virtual:
	// سيتم استدعاء دالة الموظف وليس دالة الأب
	Person1->Print();

	// سيتم استدعاء دالة الطالب وليس دالة الأب
	Person2->Print();

	return 0;
}