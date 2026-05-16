#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

string  ReadStringDate()
{
    string S1;
    cout << "Please Enter Date dd/mm/yyyy? ";
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

stDate StringToDateStructure(string DateString)
{
    stDate Date;

    vector <string> vString;

    vString = SplitString(DateString, "/");

    Date.Day = stoi(vString[0]);
    Date.Month = stoi(vString[1]);
    Date.Year = stoi(vString[2]);

    return Date;
}

string JoinString(vector <string> vString, string Delim)
{
    string S1 = "";

    for (string& s : vString)
    {
        S1 = S1 + s + Delim;
    }

    return S1.substr(0, S1.length() - Delim.length());
}

string DateToString(stDate Date)
{
    vector <string> vDate;

    vDate.push_back(to_string(Date.Day));
    vDate.push_back(to_string(Date.Month));
    vDate.push_back(to_string(Date.Year));

    return JoinString(vDate, "/");
}

int main()
{
    string DateString = ReadStringDate();

    stDate Date = StringToDateStructure(DateString);
    
    printf("\nDay: %d\n", Date.Day);
    printf("Month: %d\n", Date.Month);
    printf("Year: %d\n", Date.Year);

    printf("\nYou Entered: %s", DateToString(Date).c_str());

    system("pause>0");
}