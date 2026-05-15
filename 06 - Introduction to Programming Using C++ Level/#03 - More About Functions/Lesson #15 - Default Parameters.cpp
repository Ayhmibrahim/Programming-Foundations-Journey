#include <iostream>
using namespace std;

int MySum(int a, int b, int c = 0, int d = 0)
{
    return (a + b + c + d);
}

int main(){

    std::cout << "Sum Number is: " << MySum(10, 20) << endl;
    std::cout << "Sum Number is: " << MySum(10, 20, 30) << endl;
    std::cout << "Sum Number is: " << MySum(10, 20, 30, 40) << endl;

    return 1;

}