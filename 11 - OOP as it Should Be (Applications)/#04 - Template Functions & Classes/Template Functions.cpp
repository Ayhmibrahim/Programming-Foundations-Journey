#include <iostream>
using namespace std;



template <typename T> T MyMax(T Number1, T Number2)
{
	return (Number1 > Number2) ? Number1 : Number2;
}

int main()
{
	cout << MyMax<int>(4, 5) << endl;

	cout << MyMax<string>("Ayhm", "Ibrahim") << endl;


}