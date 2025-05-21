#include<iostream>
#include <stdlib.h>
using namespace std;

int hasSum(int a[],int total,int temp){

  for(int i=0;i<temp;i++){
        int sum=0;
    for(int count=i;count<temp;count++){
    sum=sum+a[count];
    if(sum==total)
return true;
}
}

}

int main(){
   
    int total,temp;
    cout<<"Enter Array Size : ";
    cin>>temp;
    cout<<"Enter Total : ";
    cin>>total;

    int a[100]={0};
    for(int count=0;count<temp;count++){
        cout<<"Enter Array Number : ";
        cin>>a[count];
    }
    if(hasSum(a,total,temp)==1)
    cout<<"true";
    else
    cout<<"false";
    
    return 0;
    
}