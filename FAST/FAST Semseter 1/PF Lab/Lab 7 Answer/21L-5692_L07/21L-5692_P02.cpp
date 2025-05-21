#include <iostream>
using namespace std;

void rectangle(int l,int w){
     int count=0;
    while(count<l){
        count++;
    for(int i = 0; i < w; i++){
    cout<<"0";
    }
cout<<endl;
}
}

int main(){
    int length,width;
    cout << "Enter Length: ";
    cin>>length;
    cout << "Enter Width: ";
    cin>>width;
   
   if ((length<0) || (width<0)){
       cout<<"Rectangle printing is not possible.";
   }
   rectangle(length,width);
}