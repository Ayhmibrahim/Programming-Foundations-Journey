//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#include <iostream>
using namespace std;

// ==========================================
// Abstract Class / Interface / Contract
// ==========================================
//
// هذا الكلاس يعتبر Abstract Class
// يعني: لا يمكن إنشاء كائن (Object) منه مباشرة.
//
// الهدف منه:
// وضع "قوانين" أو "عقد" يجب على أي كلاس يرث منه أن يطبقه.
//
// الدوال التي تحتوي = 0 تسمى:
// Pure Virtual Functions
//
class clsMobile
{
public:

    // دالة اتصال
    // = 0 تعني أن الدالة إجبارية على الأبناء
    virtual void Dial(string PhoneNumber) = 0;

    // دالة إرسال رسالة
    virtual void SendSMS(string PhoneNumber, string Text) = 0;

    // دالة التقاط صورة
    virtual void TakePicture() = 0;
};

// ==========================================
// iPhone Class
// ==========================================
//
// هذا الكلاس ورث من clsMobile
// لذلك يجب عليه تنفيذ جميع الدوال الموجودة في الأب.
//
// كأنه وقع "عقد" Contract.
//
class clsiPhone : public clsMobile
{
public:

    // تنفيذ دالة الاتصال
    void Dial(string PhoneNumber)
    {
        cout << "iPhone Calling: " << PhoneNumber << endl;
    }

    // تنفيذ دالة إرسال الرسالة
    void SendSMS(string PhoneNumber, string Text)
    {
        cout << "iPhone SMS To: " << PhoneNumber << endl;
    }

    // تنفيذ دالة التصوير
    void TakePicture()
    {
        cout << "iPhone Camera Opened\n";
    }

    // دالة خاصة بالآيفون فقط
    void MyOwnMethod()
    {
        cout << "Special iPhone Method\n";
    }
};

// ==========================================
// Samsung Class
// ==========================================
//
// أيضًا هذا الكلاس ملزم بتنفيذ جميع الدوال
//
class clsSamsungNote10 : public clsMobile
{
public:

    void Dial(string PhoneNumber)
    {
        cout << "Samsung Calling: " << PhoneNumber << endl;
    }

    void SendSMS(string PhoneNumber, string Text)
    {
        cout << "Samsung SMS To: " << PhoneNumber << endl;
    }

    void TakePicture()
    {
        cout << "Samsung Camera Opened\n";
    }
};

int main()
{
    // مسموح إنشاء كائنات من الكلاسات الأبناء
    clsiPhone iPhone1;
    clsSamsungNote10 Note10;

    // تجربة الدوال
    iPhone1.Dial("0501234567");
    iPhone1.TakePicture();

    cout << "-----------------\n";

    Note10.Dial("0559999999");
    Note10.TakePicture();

    system("pause>0");
    return 0;
}