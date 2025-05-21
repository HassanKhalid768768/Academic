#include <iostream>
using namespace std;

void TableNumber(int n,int t ,int c){
while(t!=0){   
   while(c!=0){
       cout<<t<<" ";
       c--;
   }
   t--;
   c=t;
   cout<<endl;
}
}

int main()
{
   int Number,temp=0,counter=0;
   cout<<"Enter Number : ";
   cin>>Number;
   counter=Number;
   temp=Number;
TableNumber(Number,temp,counter);
}

