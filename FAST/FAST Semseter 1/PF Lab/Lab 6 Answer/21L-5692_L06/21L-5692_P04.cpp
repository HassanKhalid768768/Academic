#include <iostream>
using namespace std;

void Mathematics(double n1,double n2 ,int c){
    if (c==1){
        cout<<n1+n2;
    }
     if (c==2){
        cout<<n1-n2;
    }
     if (c==3){
        cout<<n1*n2;
    }
     if (c==4){
        cout<<n1/n2;
    }
}

int main()
{
    cout<<"Choice 1 +  Choice 2 -  Choice 3 *  Choice 4 /"<<endl;
   double Number1,Number2;
   int Choice;
   cout<<"Enter Number 1 : "<<endl;
   cin>>Number1;
   cout<<"Enter Number 2 : "<<endl;
   cin>>Number2;
   cout<<"Enter Choice : "<<endl;
   cin>>Choice;
  
Mathematics(Number1,Number2,Choice);
}

