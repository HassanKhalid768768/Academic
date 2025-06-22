#include <iostream>

using namespace std;

int main()
{
 int a,square,cube,half;
 cout<<"Enter the value of a : ";
 cin>>a;
 

int* ptrA;
 ptrA = &a;
 
  cout<<"Square of numbers is : " << *ptrA * *ptrA<<endl;
  cout<<"Cube of numbers is : " << *ptrA * *ptrA * *ptrA<<endl;
  cout<<"Half of numbers is : " << *ptrA / 2<<endl;

 system("pause");
    return 0;
}