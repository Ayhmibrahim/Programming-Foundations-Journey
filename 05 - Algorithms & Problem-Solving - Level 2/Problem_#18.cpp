#include <iostream>
#include <string>
using namespace std;

string ReadText()
{
    string Text;

    cout << "Please enter a text?\n";
    getline(cin, Text);

    return Text;
}

string EncrypText(string Text, short EncrypText)
{
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + EncrypText);
    }
    
    return Text;
}

string DecrypText(string Text, short EncrypText)
{
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] - EncrypText);
    }
    
    return Text;
}
int main()
{
    
    const short EncrypionKey = 2;

    string Text = ReadText();
    string TextAfterEncrypion = EncrypText(Text, EncrypionKey);
    string TextAfterDecrypion = DecrypText(TextAfterEncrypion, EncrypionKey);

    cout << "\nText Before Encrypion : " << Text << endl;
    cout << "\nText After Encrypion : " << TextAfterEncrypion << endl;
    cout << "\nText After Decrypion : " << TextAfterDecrypion << endl;

    return 0;
}