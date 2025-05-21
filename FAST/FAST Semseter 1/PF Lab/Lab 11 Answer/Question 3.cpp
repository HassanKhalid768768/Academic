#include <iostream>
using namespace std;

void remchar(char Text[],int LENGTH){
    for(int i=0;i<=LENGTH;i++){
       if( (int)Text[i]>='A'&&(int)Text[i]<='Z' ){
           cout<<Text[i];
       }
      if( (int)Text[i]>='a'&&(int)Text[i]<='z' ) {
          cout<<Text[i];
      }
      if( (int)Text[i]=='\0' ) {
          cout<<Text[i];
      }
    }
}






int main(){

char TEXT[100];
int Length;

    cout<<"Enter TEXT : ";
    cin.get(TEXT, 100);
    cout<<endl<<"Enter Length : ";
    cin>>Length;

    remchar(TEXT,Length);



return 0;
}
