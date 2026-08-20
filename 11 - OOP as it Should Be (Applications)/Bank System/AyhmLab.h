#pragma once
#include<iostream>

using namespace std;

namespace ay
{

    int ReadPositiveNumber(string Message)
    {
        int Number = 0;
        do
        {
            cout << Message << endl;
            cin >> Number;

        } while (Number <= 0);


        return Number;
    }

    int RandomNumber(int From, int To)
    {

        int randNum = rand() % (To - From + 1) - From;
        return randNum;
    }

    void Swap(int& A, int& B)
    {
        int Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    string Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }

        return t;
    }

}