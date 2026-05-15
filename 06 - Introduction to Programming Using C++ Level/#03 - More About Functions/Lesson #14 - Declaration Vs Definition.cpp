#include <iostream>
using namespace std;


//هنا نستدعي بس السطر الاول للفنكشن عشان نعرف الكموبيلر انه موجود تحت
void add(int, int);

int main()
{
    add(15, 12);

    return 0;
}


//هنا يكون مكان الفانكشن الامر لو احنا نحب نرتب الكود ومايكون زحمة فانكشن فوق نسويه تحت عشان
//يسمى اندفايند
void add(int a, int b)
{
    std::cout<<"Sum Number is: " << a + b << endl;
}