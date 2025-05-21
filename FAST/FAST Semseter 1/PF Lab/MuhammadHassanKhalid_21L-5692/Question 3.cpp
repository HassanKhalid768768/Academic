#include <iostream>
using namespace std;

int main()
{
      int t,before,beforebefore;
    int Sequence;
   cout<<"Enter Sequence Length: ";
   cin>>Sequence;
   cout<<endl;
   cout<<"Enter "<<Sequence<<" terms of the sequence: ";
   for(int i=1;i<=Sequence;i++){
   cin>>t;
   if(i==Sequence-2){
   beforebefore=t;
   }
   if(i==Sequence-1){
   before=t;
   }
   }
   if((before<beforebefore)&&(t>before)){
       cout<<"The sequence is ZIG-ZAG";
   }
       else{
    cout<<"The sequence is NOT ZIG-ZAG";
   }
       
    return 0;
}