#include <iostream>
using namespace std;

void countAllLetters(char Text[], int Length){
    for(int i=0;i<=Length-1;i++){
        char Character=Text[i];
        int sum=0;
         for(int j=0;j<=Length-1;j++){
        if (Character==Text[j]){
            sum=sum+1;
        }
         }
        cout<<"Occurences of "<<Character<<" are : "<<sum<<endl;
        
    }
    
  
}

int main(){

char TEXT[100];
int LENGTH;

    cout<<"Enter Text : ";
    cin.get(TEXT, 100);
    cout<<endl<<"Enter Length : ";
    cin>>LENGTH;
    
    countAllLetters(TEXT,LENGTH);
    
return 0;
}