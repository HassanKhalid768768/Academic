#include <iostream>
using namespace std;



int main(){
    int numbers[12],flip[12];
    for(int count=1;count<=12;count++){
    cout<<"Enter Number : ";
    cin>>numbers[count];
    }
    int i=12;
    for(int count=1;count<=12;count++){
    flip[count]=numbers[i];
    i--;
    }
    for(int count=1;count<=12;count++){
cout<<flip[count]<<"  ";
if((count==4)||(count==8)){
    cout<<endl;
}
}
    
return 0;
}