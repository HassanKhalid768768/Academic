#include <iostream>
using namespace std;

int main()
{
    int Sum=0,Number;
    cout<<"Enter a number: ";
    cin>>Number;
    
    for(int i=1;i!=Number;i++){
        if(Number%i==0){
            Sum=Sum+i;
        }
    }
    if(Sum==Number){
        cout<<Number<<" is a perfect number";
        }
    else{
         cout<<Number<<" is not a perfect number";
    }
      return 0;
}