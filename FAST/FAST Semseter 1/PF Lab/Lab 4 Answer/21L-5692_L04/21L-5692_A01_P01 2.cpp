#include <iostream>
using namespace std;

int main(){
    int count=0,n;
    cout << "Enter Number: ";
    cin >> n;
    
    
    for(int i = 0; i < n; i++){
cout<<"* ";
}
cout<<endl;


    while(count<n-2){
        count++;
        cout<<"* ";
    for(int i = 0; i < n-2; i++){
cout<<"  ";
}
cout<<"* ";
cout<<endl;
}


for(int i = 0; i < n; i++){
cout<<"* ";
}
cout<<endl;

    return 0;
}