#include <iostream>
#include <string>

 using namespace std;

string ReadText()
{
    string Text;
    cout << "Please enter Text?\n";
    getline(cin, Text);

    return Text;
}

string EncrptText(string Text, short EncryptionKey)
{
    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char( (int) Text[i] + EncryptionKey); 
    }

    return Text;
}

string DecryptText(string Text, short EncryptionKey)
{
    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char( (int) Text[i] - EncryptionKey);
    }

    return Text;
}


int main()
{
    const short EncryptionKey = 2;

    string Text = ReadText();
    string TextAfterEncryprtion = EncrptText(Text, EncryptionKey);
    string TextAfterDecryption = DecryptText(TextAfterEncryprtion, EncryptionKey);


    cout << "\nText Befor Encryption : " << Text << endl;
    cout << "Text After Encryption : " << TextAfterEncryprtion << endl;
    cout << "Text After Decryption : " << TextAfterDecryption << endl;

    return 0;
}