#include <iostream>
using namespace std;

void cin_Array(int arr[] , int n){
 for(int count=1;count<=n;count++){
 cout<<"Enter Number : ";
 cin>>arr[count];
}
}

void cout_Array(int arr[] , int n){
for(int count=1;count<=n;count++){
cout<<arr[count]<<endl;
}
}

int main(){
    int Array[10],Numbers;
    cout<<"Enter Numbers to be input : ";
    cin>>Numbers;
  
   cin_Array(Array,Numbers);
   cout_Array(Array,Numbers);
    
    
return 0;
}