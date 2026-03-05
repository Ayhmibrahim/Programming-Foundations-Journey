#include <iostream>
#include <string>

 using namespace std;

struct stPiggyBankeContenet
{
    int Penny, Nickle, Dime, Quarter, Dollar;
};

stPiggyBankeContenet ReadPiggyBankeContenet()
{
    stPiggyBankeContenet PiggyBankeContenet;

    cout << "Please Enter a Total Pennies?" << endl;
    cin >> PiggyBankeContenet.Penny;

    cout << "Please Enter a Total Nickles?" << endl;
    cin >> PiggyBankeContenet.Nickle;

    cout << "Please Enter a Total Dimes?" << endl;
    cin >> PiggyBankeContenet.Dime;

    cout << "Please Enter a Total Quarters?" << endl;
    cin >> PiggyBankeContenet.Quarter;

    cout << "Please Enter a Total Dollars?" << endl;
    cin >> PiggyBankeContenet.Dollar;

    return PiggyBankeContenet;
}

int CalculateTotalPennise(stPiggyBankeContenet PiggyBankeContenet)
{
    int TotalPennies;

    TotalPennies = PiggyBankeContenet.Penny * 1 + PiggyBankeContenet.Nickle * 5 + 
    PiggyBankeContenet.Dime * 10 + PiggyBankeContenet.Quarter * 25 + PiggyBankeContenet.Dollar * 100;

    return TotalPennies;
}

int main()
{
    int TotalPennies = CalculateTotalPennise(ReadPiggyBankeContenet());

    cout << endl << "Total Pennies = " << TotalPennies << endl;
    cout << endl << "Total Dollar = " << (float) TotalPennies / 100;

    return 0;
}