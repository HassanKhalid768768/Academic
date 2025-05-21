using namespace std;
#include <iostream>
int main(){
    int Total,R5000,R1000,R500;
    cout<<"Enter 5000 Rupee Notes"<<endl;
    cin >> R5000;
     cout<<"Enter 1000 Rupee Notes"<<endl;
    cin >> R1000;
     cout<<"Enter 500 Rupee Notes"<<endl;
    cin >> R500;
    Total=((5000*R5000)+(1000*R1000)+(500*R500));
    cout<<"Total Amount Present in ATM Machiine :"<<Total<<endl;
return 0;
}