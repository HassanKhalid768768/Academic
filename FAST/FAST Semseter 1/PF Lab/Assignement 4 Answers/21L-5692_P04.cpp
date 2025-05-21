#include <iostream>
using namespace std;

void catsAndMouse(int s1,int s2,int s3){
    int temp1,temp2;
temp1=s1-s3;
if (temp1<0){
    temp1=temp1*-1;
}
temp2=s2-s3;
if (temp2<0){
    temp2=temp2*-1;
}
if (temp1>temp2){
    cout<<"Cat B";
}
if (temp1<temp2){
    cout<<"Cat A";
}
if (temp1==temp2){
    cout<<"Mouse C";
}
}

int main() {
    int Start1,Start2,Start3;
    cout << "Enter 3 Positions : ";
    cin >> Start1 >> Start2 >> Start3;
    catsAndMouse(Start1,Start2,Start3);
}