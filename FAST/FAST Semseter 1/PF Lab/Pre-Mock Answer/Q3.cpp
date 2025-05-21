#include <iostream>
using namespace std;

int main()
{
    int n,n1=0;
    int Numbers;
    cout<<"Enter Numbers to be entered : ";
    cin>>Numbers;
    cout<<endl;
    for(int i=1;i<=Numbers;i++){
         n1=n;
        cout<<"Enter Number : ";
        cin>>n;
        cout<<endl;
        
       
    }
    if(n<n1){
            cout<<"ZAG-ZIG Sequence";
        }
        else if(n>n1){
            cout<<"ZIG-ZAG Sequence";
        }
        else{
            cout<<"NEITHER";
        }
    
    return 0;
}