#include <iostream>
using namespace std;

int main()
{
  double Change=0,Sum=0,D=1,Q=0.25,d=0.1,n=0.05;
 cout<<"Enter Money : \n1 D for dollar\n2 Q for quarter\n3 d for dime\n4 n for nickel\n";
  while(Sum<3.5){
      int i;
      cin>>i;
      if(i==1){
          Sum+=1;
          }
      else if(i==2){
          Sum+=0.25;
          }
      else if(i==3){
          Sum+=0.1;
          }
     else if(i==4){
          Sum+=0.05;
          }
          else{
              cout<<"Wrong Choice Entered\n";
          }
    cout<<"Money Entered Till Now : "<<Sum<<endl;
  }
  Change=Sum-3.5;
  cout<<"Enjoy your deep-fried Twinkie";
  cout<<"\nChange : "<<Change;
    return 0;
}