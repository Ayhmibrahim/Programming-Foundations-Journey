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

stDate StringToDate(string DateString)
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

string LowerAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {

        S1[i] = tolower(S1[i]);

    }

    return S1;
}

string ReplaceWordInStringUsingBuiltInFunction(string S1, string
    StringToReplace, string sRepalceTo)
{

    short pos = S1.find(StringToReplace);

    while (pos != std::string::npos)
    {

        S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);

        pos = S1.find(StringToReplace);
    }

    return S1;
}

string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormattedDateString = "";
    FormattedDateString = ReplaceWordInStringUsingBuiltInFunction(DateFormat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInStringUsingBuiltInFunction(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInStringUsingBuiltInFunction(FormattedDateString, "yyyy", to_string(Date.Year));

    return FormattedDateString;
}

int main()
{
    string DateString = ReadStringDate();
        stDate Date = StringToDate(DateString);
  


        system("pause>0");
    return 0;
}