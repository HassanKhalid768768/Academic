#include<iostream>
using namespace std;

void i_am_joking(int n){
    int remain;
     int Sum=0;

    for(int i=n;i!=0;i=n){
       
    remain=n%10;
    Sum=Sum+remain;
    n=n/10;
    }
    if (Sum>9)
        i_am_joking(Sum);
    else
        cout<<Sum;

}
    




int main() {
int number;
cout<<"Enter number ";
cin>>number;
cout<<endl<<endl;
i_am_joking(number);

}