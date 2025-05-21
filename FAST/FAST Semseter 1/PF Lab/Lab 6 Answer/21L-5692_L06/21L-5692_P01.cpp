#include <iostream>
using namespace std;

void MaxandMin(int n1,int n2,int n3){
    if((n1>n2)&&(n1>n3)){
        cout<<"Max Num is : "<<n1<<endl;
    }
    if((n2>n1)&&(n2>n3)){
        cout<<"Max Num is : "<<n2<<endl;
    }
    if((n3>n1)&&(n3>n2)){
        cout<<"Max Num is : "<<n3<<endl;
    }
    
    
    if((n1<n2)&&(n1<n3)){
        cout<<"Min Num is : "<<n1<<endl;
    }
    if((n2<n1)&&(n2<n3)){
        cout<<"Min Num is : "<<n2<<endl;
    }
    if((n3<n1)&&(n3<n2)){
        cout<<"Min Num is : "<<n3<<endl;
    }
}

int main(){
    int number1,number2,number3;
    cout<<"Enter Number 1 : "<<endl;
    cin>>number1;
    cout<<"Enter Number 2 : "<<endl;
    cin>>number2;
    cout<<"Enter Number 3 : "<<endl;
    cin>>number3;
    
    MaxandMin(number1,number2,number3);
}