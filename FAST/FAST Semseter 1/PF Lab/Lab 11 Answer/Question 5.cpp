#include <iostream>
using namespace std;

void tweakletters(char Text[],int Length,int OPTION[]){
    for(int i=0;i<=Length;i++){
        Text[i]=(int)Text[i]+OPTION[i];
        cout<<(char)Text[i];
    }
     
        
    }
    
   

int main(){

char TEXT[100];
int LENGTH;
int option[100];

    cout<<"Enter TEXT : ";
    cin.get(TEXT, 100);
    cout<<"Enter Length : ";
   cin>>LENGTH;
    
    for(int i=0;i<=LENGTH;i++){
        cout<<"Enter Option : ";
        cin>>option[i];
        cout<<endl;
    }
    
    
    tweakletters(TEXT,LENGTH,option);
    
    
    
return 0;
}