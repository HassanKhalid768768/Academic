#include <iostream>
using namespace std;
void findNthDigit(int number,int index){
   

        int remain;
        int Array[100];
        for(int i=0;number>0;i++){
           remain=number%10;
           Array[i]=remain;
           number=number/10;
        }
       
       
        cout<< Array[index];
           

}      


int main()
{
   
    int N,I;
    cout<< "Enter number and index "<< endl;
    cin>>N>>I,
    
    findNthDigit(N,I);
}