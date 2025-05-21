#include <iostream>
using namespace std;

int main()
{
   int count=0,n=0,Sum=0,Average=0,Max=0,Min=9999;
   while (n>=0){
       cout<<"Enter Number : ";
       cin>>n;
       if(n>=0){
       count++;
       Sum=Sum+n;
       if (n>Max){
           Max=n;
       }
       if (n<Min){
           Min=n;
       }
   }
    else{  
           Average=Sum/count;
           cout<<"Sum : "<<Sum<<endl;
           cout<<"Average : "<<Average<<endl;
           cout<<"Max : "<<Max<<endl;
           cout<<"Min : "<<Min<<endl;
    }
}


    return 0;
}
