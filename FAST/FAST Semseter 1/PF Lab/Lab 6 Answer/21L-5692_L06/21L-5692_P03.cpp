#include <iostream>
using namespace std;

void Table(int n,int v){
int Sum=0;
int d=v;
Sum=Sum+n;
while(d>0){
int temp=1;
for(int b=d;b!=0;){
    temp=temp*n;
    b--;
}
d=d-2;
Sum=Sum+temp;
}
cout<<Sum;
}

int main()
{
   int Number,Value;
   cout<<"Enter Number : ";
   cin>>Number;
   cout<<"Enter Value : ";
   cin>>Value;
Table(Number,Value);
}

