#include <iostream>

using namespace std;

int main()
{
 int *arr;
 int size;
 int max=0,min=999,second,index;
 do{
 	cout<<"Please enter size : ";
 	cin>>size;
 	}while (size<=0);
 arr=new int[size];
 cout<<"Please enter elements : "<<endl;
 for(int i=0;i<size;i++){
 	cin>>arr[i];
 	if(arr[i]>max){
 		max=arr[i];
	 }
	 if(arr[i]<min){
 		min=arr[i];
	 }
 }


 for(int i=0;i<size;i++){
if(arr[i]>min && arr[i]<max){
	second=arr[i];
}
}

for(int i=0;i<size;i++){
if(arr[i]==second){
index=i;
break;
}

}

cout<<endl<<"Index of First occurrence of second largest element is : "<<index;


    return 0;
}