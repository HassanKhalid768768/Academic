#include<iostream>
using namespace std;

int sumOfN(int a[],int index,int N){
    int sum=0;
    for(int count=index;count<index+N;count++){
    sum=sum+a[count];
}
return sum;
}

int main(){
   
    int index,N,temp;
    cout<<"Enter Array Size : ";
    cin>>temp;
    cout<<"Enter Index : ";
    cin>>index;
    cout<<"Enter Number : ";
    cin>>N;
    int a[100]={0};
    for(int count=0;count<temp;count++){
        cout<<"Enter Array Number : ";
        cin>>a[count];
    }
    cout<<"Sum = "<<sumOfN(a,index,N);
    return 0;
    
}