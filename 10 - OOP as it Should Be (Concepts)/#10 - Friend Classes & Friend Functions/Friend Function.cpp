#include<iostream>
using namespace std;

class clsA
{
private:
    int _Var1;

protected:
    int _Var3;

public:
    int Var2;

    clsA()
    {
        _Var1 = 10;
        Var2 = 20;
        _Var3 = 30;
    }

    // friend function:
    // أعطينا الدالة MySum صلاحية خاصة
    // للوصول إلى private و protected
    friend int MySum(clsA A1);
};

// دالة عادية وليست داخل الكلاس
int MySum(clsA A1)
{
    // مسموح الوصول بسبب friend function
    return A1._Var1 + A1.Var2 + A1._Var3;
}

/*
// هذه الدالة ليست friend
// لذلك سيظهر Error
int Fun2(clsA A1)
{
    return A1._Var1 + A1.Var2 + A1._Var3;
}
*/

int main()
{
    clsA A1;

    cout << MySum(A1);

    return 0;
}