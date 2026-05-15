#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct stPassWord
{
	bool hasUpper = 0;
	bool hasLower = 0;
	bool hasDigit = 0;
	bool hasSpecial = 0;
};

string ReadSentece()
{
    string PassWord;  
    cout << "\nPlease enter a Password? ";
	getline(cin, PassWord);
    return PassWord;
}

void CheckCCtype(stPassWord &PassWord, string Password)
{
	for (int i = 0; i < Password.length(); i++)
	{
		if (isupper(Password[i]))
			PassWord.hasUpper = 1;
		else if (islower(Password[i]))
			PassWord.hasLower = 1;
		else if (isdigit(Password[i]))
			PassWord.hasDigit = 1;
		else if (ispunct(Password[i]))
			PassWord.hasSpecial = 1;
	}
}

int GetPasswordScore(stPassWord PassWord)
{
	int score = 0;
	if (PassWord.hasUpper) score++;
	if (PassWord.hasLower) score++;
	if (PassWord.hasDigit) score++;
	if (PassWord.hasSpecial) score++;
	return score;
}

string GetStrength(string Password, stPassWord PassWord)
{
	if (Password.length() < 8)
		return "Weak (too short)";

	int score = GetPasswordScore(PassWord);

	if (score <= 1) return "Weak";
	else if (score == 2 || score == 3) return "Medium";
	else return "Strong";
}

void PrintResults()
{
	string Password = ReadSentece();
	stPassWord PassInfo;

	CheckCCtype(PassInfo, Password);


	cout << "\nPassword length >= 8? "
		<< (Password.length() >= 8 ? "Yes" : "No") << endl;

	cout << "Password strength: " << GetStrength(Password, PassInfo) << endl;
}

int main()
{
	
	PrintResults();

	return 0;
}