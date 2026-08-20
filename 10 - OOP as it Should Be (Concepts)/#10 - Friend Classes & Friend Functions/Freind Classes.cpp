//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#include<iostream>
using namespace std;

// ==========================================
// Class A
// ==========================================
class clsA
{
private:

    // private:
    // لا يمكن الوصول له خارج الكلاس
    int _Var1;

protected:

    // protected:
    // يمكن الوصول له داخل الكلاس والأبناء فقط
    int _Var3;

public:

    // public:
    // يمكن الوصول له من أي مكان
    int Var2;

    // Constructor
    clsA()
    {
        _Var1 = 10;
        Var2 = 20;
        _Var3 = 30;
    }

    // ==========================================
    // Friend Class
    // ==========================================
    //
    // هذا السطر يعطي clsB صلاحية كاملة
    // للوصول إلى جميع أعضاء clsA
    // حتى private و protected
    //
    friend class clsB;
};

// ==========================================
// Class B
// ==========================================
class clsB
{
public:

    // دالة تستقبل كائن من clsA
    void display(clsA A1)
    {
        // الوصول إلى private مسموح
        // بسبب friend class
        cout << endl << "The value of Var1 = "
            << A1._Var1;

        // public طبيعي يمكن الوصول له
        cout << endl << "The value of Var2 = "
            << A1.Var2;

        // الوصول إلى protected مسموح
        // بسبب friend class
        cout << endl << "The value of Var3 = "
            << A1._Var3;
    }
};

int main()
{
    // إنشاء كائن من clsA
    clsA A1;

    // إنشاء كائن من clsB
    clsB B1;

    // استدعاء الدالة display
    B1.display(A1);

    system("pause>0");
    return 0;
}
/*
شرح مبسط :

friend class تعني إعطاء كلاس آخر صلاحية خاصة
للوصول إلى جميع بيانات الكلاس حتى لو كانت :

-private
- protected

في هذا المثال :
clsB يعتبر "صديق" لـ clsA
لذلك استطاع الوصول إلى :

_Var1  -> private
_Var3  -> protected

وكأنه أخذ تصريح خاص أو "واسطة" 😄

بدون friend class سيظهر Error
لأن private و protected ممنوع الوصول لها من الخارج.*/