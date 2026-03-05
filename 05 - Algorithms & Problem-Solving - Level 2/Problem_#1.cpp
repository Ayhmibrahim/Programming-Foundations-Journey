#include <iostream>
using namespace std;

void PrintTableHeader()
{
    
    cout << "\n\n\t\t\t Multipliaction Table Form 1 to 10\n\n";
    for (int i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }
    cout << "\n___________________________________________________________________________________\n";
}

string ColumSperator(int i)
{
    if (i < 10)
        return "  |";
    else
        return " |";

}

void PrintMultipaction()
{
    PrintTableHeader();

    for (int i = 1; i <= 10; i++)
    {
        cout << " " << i << ColumSperator(i) << "\t";
        for (int j = 1; j <= 10; j++)
        {
            cout << i * j << "\t";

        }
        cout << endl;
    }
}
int main()
{
 
    PrintMultipaction();
    

    return 0;
}