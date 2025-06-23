#include<iostream>
using namespace std;

template <typename T>

T range(T **array , int rows,int columns)

{

T max = array[0][0];
T min = array[0][0];



for(int i = 0; i < rows; i++){
for(int j = 0; j < columns; j++){
if(array[i][j] > max){
max = array[i][j];
}
if(array[i][j] < min){
min = array[i][j];
}
}
}


T result = ((max - min) / 4) + min;

return result;

}

int main()

{

int ** arr = new int*[4];



for(int i = 0; i< 4 ; i++)

arr[i] = new int[4];


int c = 0;

for(int i= 0; i< 4; i++)

for(int j = 0; j<4 ;j++)

arr[i][j] = c++;

char count = 'A';

char ** arr1 = new char*[3];

for(int i = 0; i< 3 ; i++)

arr1[i] = new char[3];


for(int i= 0; i< 3; i++)

for(int j = 0; j<3 ;j++)

arr1[i][j] = count++;


cout<<"Range Number : "<<range(arr,4,4);

cout<<"\nRange Alphabet : "<<range(arr1,3,3);

}
