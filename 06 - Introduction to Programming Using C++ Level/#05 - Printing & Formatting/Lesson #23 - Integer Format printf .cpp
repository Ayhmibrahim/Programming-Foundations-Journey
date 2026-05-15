#include <iostream>
using namespace std;


int main()
{
    int Page = 1, TotalPages = 10;

    // print string and int variable
    printf("The Page number = %d \n", Page);
    printf("The Page number = %d of %d \n", Page , TotalPages);

    //Width specification
    printf("The Page number = %0*d \n",2, Page);
    printf("The Page number = %0*d \n",3, Page);
    printf("The Page number = %0*d \n",4, Page);
    printf("The Page number = %0*d \n",5, Page);
    
    int Number1 = 20, Number = 30;
    printf("The Result of %d + %d = %d \n", Number, Number1,Number + Number1);


    return 0;
}