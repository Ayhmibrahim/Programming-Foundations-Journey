#include <iostream>
using namespace std;

// الكلاس الأساسي (Base Class)
class clsA
{
private:

    // private => لا يمكن الوصول لها خارج clsA
    // ولا حتى من الكلاسات المشتقة
    int V1;

    int Fun1()
    {
        return 1;
    }

protected:

    // protected => يمكن الوصول لها داخل clsA
    // وكذلك داخل الكلاسات المشتقة فقط
    int V2;

    int Fun2()
    {
        return 2;
    }

public:

    // public => يمكن الوصول لها من أي مكان
    int V3;

    int Fun3()
    {
        return 3;
    }
};


// ===============================================
// جرّب تغيير private إلى public أو protected
// وشاهد ماذا يحدث
// ===============================================


// هنا الوراثة PRIVATE
class clsB : private clsA
{
public:

    int Fun4()
    {
        // داخل الكلاس المشتق نستطيع الوصول إلى:
        // V2 لأنه protected
        // V3 لأنه public في clsA

        // لكن بعد private inheritance:
        // V2 يصبح private داخل clsB
        // V3 يصبح private داخل clsB

        return V2 + V3;
    }
};


// clsC يرث من clsB
class clsC : public clsB
{
public:

    int Fun5()
    {
        // هنا لن نستطيع الوصول إلى V2 أو V3

        // لماذا؟
        // لأن clsB ورث clsA بطريقة private
        // وبالتالي كل أعضاء clsA أصبحت private داخل clsB
        // والـ private لا ينتقل للكلاس المشتق

        return 5;
    }
};


int main()
{

    clsB B1;

    // =========================================
    // ماذا نستطيع الوصول له في B1 ؟
    // =========================================

    // B1.V3; ❌ خطأ
    // لأن public من clsA أصبح private داخل clsB

    // B1.Fun3(); ❌ خطأ
    // نفس السبب

    // B1.V2; ❌ خطأ
    // protected أصلاً لا يُرى خارج الكلاس

    // B1.Fun4(); ✅ صحيح
    // لأنه public داخل clsB



    clsC C1;

    // =========================================
    // ماذا نستطيع الوصول له في C1 ؟
    // =========================================

    // C1.V3; ❌ خطأ
    // لم يعد public بسبب private inheritance

    // C1.Fun3(); ❌ خطأ

    // C1.Fun4(); ✅ صحيح
    // لأنه public في clsB وانتقل كـ public إلى clsC

    // C1.Fun5(); ✅ صحيح



    return 0;
}