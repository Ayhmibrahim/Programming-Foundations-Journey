#include <iostream>
#include <string>
#include <vector>

using namespace std;

string RemovePunctuations(string S1)
{
	string S2 = "";

	for (short i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i]))
		{
			S2 += S1[i];
		}
	}

	return S2;

}

int main()
{
	string S1 = "Welcome to Yeman , Yeman is a nice country";


	cout << "Orignal String:\n" << S1;

	cout << "\n\nPunctuations Removed: \n" <<
		RemovePunctuations(S1) << endl;;

	system("pause>0");
}
