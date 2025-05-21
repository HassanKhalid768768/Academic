#include<iostream>
using namespace std;

void Addition(int A,int B){
    int sum;
    sum=A+B;
    cout<<sum<<endl<<endl;
}

void Multiplication(int A,int B){
    int mul;
    mul=A*B;
    cout<<mul<<endl<<endl;
}

void Table(int A){
    for(int i=1;i<=10;i++){
        cout<<A<<"  "<<"*  "<<i<<"  =  "<<A*i<<endl;
    }
    cout<<endl<<endl;
}

void Square(int A){
    int square=A*A;
    cout<<square;
}


int main() {
int a ,b;
cout<<"Enter a and b value ";
cin>>a>>b;
cout<<endl;

Addition(a,b);
Multiplication(a,b);
Table(a);
Square(a);
}