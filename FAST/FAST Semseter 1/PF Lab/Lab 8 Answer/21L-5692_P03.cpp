#include<iostream>
using namespace std;

void digitMul(int n){
    int remain,Mul=1;
    for(int i=n;i!=0;i=n){
    remain=n%10;
    Mul=Mul*remain;
    n=n/10;
    }
    cout<<Mul;
}


int main() {
int number;
cout<<"Enter number ";
cin>>number;
cout<<endl<<endl;

digitMul(number);

}