#include <iostream>
using namespace std;

int main()
{
    int Largest,Larger,Large,Number1,Number2,Number3;
     cout<<"Please Enter Number 1 ";
        cin>>Number1;
        cout<<"Please Enter Number 2 ";
        cin>>Number2;
        cout<<"Please Enter Number 3 ";
        cin>>Number3;
       if ((Number1>Number2)&&(Number1>Number3)){
            Largest=Number1;
       }
            if ((Number2>Number1)&&(Number2>Number3)){
            Largest=Number2;
            }
            if ((Number3>Number1)&&(Number3>Number2)){
            Largest=Number3;
        }
        if (Number1<Largest){
            Larger=Number1;
        }
        if (Number2<Largest){
            Larger=Number2;
        }
        if (Number3<Largest){
            Larger=Number3;
        }
        if (Number1<Larger){
            Large=Number1;
        }
        if (Number2<Larger){
            Large=Number2;
        }
        if (Number3<Larger){
            Large=Number3;
        }
    cout<<Largest<<endl;
    cout<<Larger<<endl;
    cout<<Large<<endl;
    return 0;
}
