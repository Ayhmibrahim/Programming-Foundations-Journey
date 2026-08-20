// ProgrammingAdvices.com
// Mohammed Abu-Hadhoud

#include <stack>
#include <iostream>
using namespace std;

int main()
{
    // stack container declaration
    stack<string> MyStack1;
    stack<string> MyStack2;

    // pushing elements into first stack
    MyStack1.push("Ayhm");
    MyStack1.push("Ibrahim");
    MyStack1.push("Mohmmed");
    MyStack1.push("Almwmre");
 

    // pushing elements into 2nd stack
  
    MyStack1.push("Mogmmed");
    MyStack1.push("Ebrhim");
    MyStack1.push("Aldemise");
    MyStack1.push("Manger");


    // using swap() function to swap elements of stacks
    MyStack1.swap(MyStack2);

    // printing the first stack
    cout << "MyStack1 = ";
    while (!MyStack1.empty()) {
        cout << MyStack1.top() << " ";
        MyStack1.pop();
    }

    // printing the second stack
    cout << endl << "MyStack2 = ";
    while (!MyStack2.empty()) {
        cout << MyStack2.top() << " ";
        MyStack2.pop();
    }

    system("pause>0");

    return 0;


}