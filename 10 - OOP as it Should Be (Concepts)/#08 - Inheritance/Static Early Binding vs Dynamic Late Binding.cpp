#include <iostream>

using namespace std;

// الكلاس الأساسي (Base Class)
class clsPerson
{

public:

    // virtual تجعل البرنامج يختار الدالة
    // حسب نوع الكائن الحقيقي وقت التشغيل (Runtime)
    virtual void Print()

    {
        cout << "Hi, i'm a person!\n";
    }

};

// كلاس الموظف يرث من clsPerson
class clsEmployee : public clsPerson
{
public:

    // إعادة تعريف الدالة Print
    void Print()
    {
        cout << "Hi, I'm an Employee\n";
    }
};

// كلاس الطالب يرث من clsPerson
class clsStudent : public clsPerson
{
public:

    // إعادة تعريف الدالة Print
    void Print()
    {
        cout << "Hi, I'm a student\n";
    }
};

int main()

{
    // إنشاء كائن موظف
    clsEmployee Employee1;

    // إنشاء كائن طالب
    clsStudent Student1;

    // =========================================
    // Early Binding (Static Binding)
    // =========================================
    // هنا البرنامج يعرف نوع الكائن مباشرة أثناء الترجمة.
    // لذلك يتم استدعاء الدالة مباشرة بدون virtual.

    Employee1.Print();
    Student1.Print();

    cout << "-------------------\n";

    // مؤشر من نوع الأب يشير إلى كائن موظف
    clsPerson* Person1 = &Employee1;

    // مؤشر من نوع الأب يشير إلى كائن طالب
    clsPerson* Person2 = &Student1;

    // =========================================
    // Late Binding (Dynamic Binding)
    // =========================================
    // هنا المؤشر من نوع clsPerson
    // لكن الكائن الحقيقي Employee أو Student.
    //
    // بسبب virtual:
    // البرنامج يحدد الدالة المناسبة وقت التشغيل.

    Person1->Print(); // يستدعي Print الخاصة بالموظف
    Person2->Print(); // يستدعي Print الخاصة بالطالب

    system("pause>0");
    return 0;
}