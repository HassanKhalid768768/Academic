#include <iostream>
using namespace std;
void Digit_Frequency( int Numbers[], int N, int F[]){
    for(int count=1;count<=10;count++){
cout<<Numbers[count]<<endl;
}
}


int main(){
    int numbers[10],n,f[10];
    for(int count=1;count<=10;count++){
    cout<<"Enter Number : ";
    cin>>numbers[count];
    cout<<endl;
    }
    Digit_Frequency(numbers,n,f);
    
return 0;
}