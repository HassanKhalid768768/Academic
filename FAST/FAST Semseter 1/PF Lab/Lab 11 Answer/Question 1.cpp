#include <iostream>
using namespace std;

void countCharacter(char Text[], int Length, char Character){
    int sum=0;
    for(int count=0;count<=100;count++){
        if (Character==Text[count]){
            sum=sum+1;
        }
    }
    cout<<"Occurences are : "<<sum;

  
}

int main(){

char TEXT[100];
int LENGTH;
char CHARACTER;

    cout<<"Enter Text : ";
    cin.get(TEXT, 100);
    cout<<endl<<"Enter Length : ";
    cin>>LENGTH;
    cout<<endl<<"Enter CHARACTER : ";
    cin>>CHARACTER;
    
    countCharacter(TEXT,LENGTH,CHARACTER);
    
return 0;
}