#include <iostream>
using namespace std;



int *Input_array(int &size){

int *arr=new int[size];
for(int i=0;i<size;i++){
   cin>> arr[i];
}
return arr;

}

int * compress_array(int*original_Arr,int &size){
	int * temporaray = new int [size];
for(int i=0;i<size;i++){
  if(original_Arr[i]==temporary[i]){
  	cout<<""
  	break;
  }
   
}
}
   return original_Arr;
}


void output_array(const int* myArray,const int &size){

for(int i=0;i<size;i++){
cout<<myArray[i];
}

}

 
 
 
 
int main(){
int size;
cout<< "Enter Size of Array"<<endl;
cin>> size;

int * array = new int [size];
 int * ptr = Input_array(size);
for(int i=0;i<size;i++){

 array[i]=*ptr++;
}
 cout<< compress_array(array,size);
    output_array(array,size);
   return 0;
}
