#include <iostream>
using namespace std;


int main()
{
    int Num;
    cout << "Enter total number of students: ";
    cin >> Num;

    float* ptr;
    
    // memory allocation of num number of floats
    ptr = new float[Num];

    cout << "Enter grades of students." << endl;

    for (int i = 0; i < Num; i++)
    {
        cout << "Student" << i+1 << ": ";
        cin >> *(ptr + i);
    }

    cout << "\nDisplaying grades of students." << endl;
    for (int i = 0; i < Num; i++)
    {
        cout << "Student" << i + 1 << ": " << *(ptr + i) << endl;
    }

    // ptr memory is released
    delete[]ptr;

    return 0;
}