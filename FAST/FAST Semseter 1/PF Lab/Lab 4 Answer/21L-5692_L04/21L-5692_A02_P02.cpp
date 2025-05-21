#include <iostream>
using namespace std;

int main(){
    int old,sequence=1,number,variable=0;
    cout << "Enter Number: ";
    cin >> number;
    cout<<"1 ";
    for(int count=0;count<number-1;count++){
        old=sequence;
   sequence=sequence+variable;
         variable=old;
    cout<<sequence<<" ";
}
    return 0;
}