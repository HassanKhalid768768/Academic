#include <iostream>
using namespace std;

int main(){
    int M2=2,M5=5,number;
    cout << "Enter Number: ";
    cin >> number;
    for(int count=0;count<number;count++){
        if (count%2==0){
        cout<<M2;
        if(count!=number){
            cout<<"-";
        }
        M2=M2+2;
        }
        if (count%2!=0){
        cout<<M5;
        if(count!=number){
            cout<<"+";
        }
        M5=M5+5;
        }
}
    return 0;
}