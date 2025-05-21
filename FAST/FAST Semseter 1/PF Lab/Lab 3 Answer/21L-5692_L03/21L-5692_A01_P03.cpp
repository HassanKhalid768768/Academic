using namespace std;
#include <iostream>
int main(){
    int Total,AmountR,R5000,R1000,R500;
    do{
    cout<<"Enter Total Amount Present in ATM MAchiine"<<endl;
    cin >> Total;
    }
    while(Total%500!=0);
    (R5000=Total / 5000);
    (AmountR=Total%5000);
    (R1000=AmountR / 1000);
    (AmountR=AmountR%1000);
    (R500=AmountR / 500);
    (AmountR=AmountR%500);
    cout<<"Total Amount Present in ATM MAchiine :"<<Total<<endl;
    cout<<"5000 Rupee Notes :"<<R5000<<endl;
    cout<<"1000 Rupee Notes :"<<R1000<<endl;
    cout<<"500 Rupee Notes :"<<R500<<endl;
return 0;
}