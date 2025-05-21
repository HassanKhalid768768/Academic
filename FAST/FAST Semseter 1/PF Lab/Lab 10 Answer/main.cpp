#include <iostream>
using namespace std;



int main(){
    int rows,columns;
   cout<<"Enter number of rows : ";
   cin>>rows;
   cout<<"Enter number of columns : ";
   cin>>columns;
    int numbers[rows][columns],flip[rows][columns];
    
    for(int j=1;j<=columns;j++){
        for(int i=1;i<=rows;i++){
    cout<<"Enter Number : ";
    cin>>numbers[j][i];
    }
    }
    
    b=columns;
    a=rows;
    
    for(int j=1;j<=columns;j++){
        for(int i=1;i<=rows;i++){
    flip[j][i]==numbers[b][a];
    a--;
    }
    b--;
    }
    
    
return 0;
}