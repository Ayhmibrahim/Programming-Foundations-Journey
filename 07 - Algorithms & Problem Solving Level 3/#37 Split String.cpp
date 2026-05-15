#include <iostream>
#include <string>
#include <vector>
using namespace std;

string  ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

vector <string> SplitString(string S1, string Delim)
{
    // فيكتور لتخزين الكلمات بعد التقسيم
    vector <string> vString;

    // متغير لحفظ موقع الفاصل داخل النص
    short pos = 0;

    // متغير لتخزين كل جزء (كلمة) بعد التقسيم
    string sWord;

    // نكرر طالما الفاصل موجود داخل النص
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        // نأخذ الجزء من بداية النص إلى قبل الفاصل
        sWord = S1.substr(0, pos);

        // إذا الكلمة مو فاضية نضيفها للفكتور
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        // نحذف الجزء اللي أخذناه + الفاصل من النص الأصلي
        S1.erase(0, pos + Delim.length());
    }

    // بعد انتهاء اللوب، يبقى آخر جزء من النص
    // إذا مو فاضي نضيفه
    if (S1 != "")
    {
        vString.push_back(S1);
    }

    // نرجع الفكتور اللي يحتوي على كل الأجزاء
    return vString;
}

int main()
{
    vector <string> vString;

    vString = SplitString(ReadString(), " ");

    cout << "\nTokens = " << vString.size() << endl;

    for (string& vNumbers  : vString)
    {
        cout << vNumbers << endl;
    }
    
    system("pause>0");
}