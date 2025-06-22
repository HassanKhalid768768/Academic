#include <iostream>

using namespace std;

int main()
{
 int *arr;
 int size;
 do{
 	cout<<"Please enter size : ";
 	cin>>size;
 }while (size<=0);
 arr=new int[size];
 cout<<"Enter "<<size<<" elements : "<<endl;
 for(int i=0;i<size;i++){
 	cin>>arr[i];
 	arr[i]=arr[i]+3;
 }
 cout<<"Resulting Array : ";
 for(int i=0;i<size;i++){
 	cout<<arr[i]<<", ";
 }



    return 0;
}