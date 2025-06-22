#include <iostream>

using namespace std;

int main()
{
 int a,b;
 cout<<"Enter the value of a : "<<endl;
 cin>>a;
 cout<<"Enter the value of b : "<<endl;
 cin>>b;

int* ptrA;
 ptrA = &a;
int* ptrB;
ptrB = &b;

*ptrA = *ptrA + 5;
*ptrB = *ptrB + 10;
cout<<*ptrA;
cout<<endl;
cout<<*ptrB;


    return 0;
}